#include "../storage/limit_storage.h"
#include "../providers/fake_provider/fake_provider.h"
#include "usage_tracker.h"

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    FakeProvider provider;
    UsageTracker tracker;
    LimitStorage limits_storage;

    while(1)
    {
        ActiveWindow activeWindow = provider.getActiveWindow();
        tracker.addSecond(activeWindow);

        int time_used = tracker.getTimeUsed(activeWindow.window_id);
        int limits = limits_storage.getLimitSeconds(activeWindow.window_id);

        std::cout << activeWindow.window_id << " time used: " << time_used << ' ' << limits << '\n'; // debug

        if(limits > 0 && time_used > limits) 
            std::cout << "Time exceeded for" << activeWindow.window_title << "\n";
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
