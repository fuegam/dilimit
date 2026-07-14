#pragma once

#include "../providers/activity_provider.h"
#include "../blockers/window_blocker.h"
#include "../storage/limit_storage.h"
#include "../notifiers/notifier.h"

#include "usage_tracker.h"
#include "cooldown_tracker.h"

class DilimitApp
{
public:
    DilimitApp(Notifier& notifier, WindowBlocker& blocker, ActivityProvider& provider, LimitStorage& limits_storage);
    void run();
private:
    Notifier& notifier_;
    WindowBlocker& blocker_;
    ActivityProvider& provider_;
    LimitStorage& limits_storage_;
    UsageTracker tracker_;
    CooldownTracker cooldown_tracker_;
    
    void tick();
    bool running_ = true;
};