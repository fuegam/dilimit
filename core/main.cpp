#include "../providers/fake_provider/fake_provider.h"
#include "../providers/activity_provider.h"

#include "../storage/limit_storage.h"
#include "usage_tracker.h"
#include "cooldown_tracker.h"

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    FakeProvider fake_provider;
    ActivityProvider& provider = fake_provider; 

    UsageTracker tracker;
    LimitStorage limits_storage;
    CooldownTracker cooldown_tracker;

    while(1)
    {
        std::vector<std::string> unblocked_apps = cooldown_tracker.countDown();
        if(!unblocked_apps.empty())
        {
            for(const auto& item : unblocked_apps)
            {
                std::cout << "Cooldown ended for: " << item << '\n';
            }
        }
        
        ActiveWindow activeWindow = provider.getActiveWindow();
        std::string curr_window_id = activeWindow.window_id;

        if(!cooldown_tracker.isBlocked(curr_window_id))
            tracker.addSecond(activeWindow);

        int time_used = tracker.getTimeUsed(curr_window_id);
        int limits = limits_storage.getLimitSeconds(curr_window_id);

        std::cout << curr_window_id << " time used: " << time_used << ' ' << limits << '\n'; // debug

        if(!cooldown_tracker.isBlocked(curr_window_id) && limits > 0 && time_used >= limits)
        {
            int limit_cooldown_time = limits_storage.getLimitCooldown(curr_window_id);

            std::cout << "Time exceeded for: " << activeWindow.window_title << "\n";
            std::cout << "Cooldown time: " << limit_cooldown_time << '\n';

            cooldown_tracker.blockApp(curr_window_id, limit_cooldown_time);
            tracker.resetUsedTime(curr_window_id);
        }
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
