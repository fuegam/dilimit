#include "dilimit_app.h"

#include <iostream>
#include <chrono>
#include <thread>

DilimitApp::DilimitApp(WindowBlocker& blocker, ActivityProvider& provider, LimitStorage& limits_storage) :
    blocker_(blocker),
    provider_(provider),
    limits_storage_(limits_storage)
{}

void DilimitApp::tick()
{
    std::vector<std::string> unblocked_apps = cooldown_tracker_.countDown();
    if(!unblocked_apps.empty())
    {
        for(const auto& item : unblocked_apps)
        {
            std::cout << "Cooldown ended for: " << item << '\n';
        }
    }

    ActiveWindow activeWindow = provider_.getActiveWindow();
    std::string curr_window_id = activeWindow.window_id;

    if(!cooldown_tracker_.isBlocked(curr_window_id))
        tracker_.addSecond(activeWindow);

    int time_used = tracker_.getTimeUsed(curr_window_id);
    int limits = limits_storage_.getLimitSeconds(curr_window_id);

    std::cout << curr_window_id << " time used: " << time_used << ' ' << limits << '\n'; // debug

    if(!cooldown_tracker_.isBlocked(curr_window_id) && limits > 0 && time_used >= limits)
    {
        int limit_cooldown_time = limits_storage_.getLimitCooldown(curr_window_id);

        std::cout << "Time exceeded for: " << activeWindow.window_title << "\n";
        std::cout << "Cooldown time: " << limit_cooldown_time << '\n';

        cooldown_tracker_.blockApp(curr_window_id, limit_cooldown_time);
        tracker_.resetUsedTime(curr_window_id);
    }
    if(cooldown_tracker_.isBlocked(curr_window_id))
    {
        blocker_.blockActiveWindow(curr_window_id);
    }
}

void DilimitApp::run()
{
    while(running_)
    {
        tick();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}