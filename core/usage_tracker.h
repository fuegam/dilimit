#pragma once

#include <map>

#include "active_window.h"

class UsageTracker
{
public:
    void addSecond(ActiveWindow activeWindow);
    void resetUsedTime(const std::string& window);
    int getTimeUsed(const std::string& window);
private:
    std::map<std::string, int> time_used;
};
