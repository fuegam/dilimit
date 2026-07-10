#pragma once

#include "../providers/activity_provider.h"
#include "../blockers/window_blocker.h"
#include "../storage/limit_storage.h"

#include "usage_tracker.h"
#include "cooldown_tracker.h"

class DilimitApp
{
public:
    DilimitApp(WindowBlocker& blocker, ActivityProvider& provider, LimitStorage& limits_storage);
    void run();
private:
    WindowBlocker& blocker_;
    ActivityProvider& provider_;
    LimitStorage& limits_storage_;
    UsageTracker tracker_;
    CooldownTracker cooldown_tracker_;
    
    void tick();
    bool running_ = true;
};