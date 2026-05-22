#include "usage_tracker.h"

void UsageTracker::addSecond(ActiveWindow activeWindow)
{
    time_used[activeWindow.window_id] += 1;
}

int UsageTracker::getTimeUsed(const std::string& window)
{
    return time_used[window];
}