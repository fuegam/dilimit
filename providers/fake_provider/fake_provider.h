#pragma once

#include <string>
#include <vector>
#include <random>

#include "../../core/active_window.h"
#include "../activity_provider.h"

class FakeProvider : public ActivityProvider
{
    public:
        FakeProvider();
        ActiveWindow getActiveWindow() override;
    private:
        std::vector<ActiveWindow> apps_data;
        ActiveWindow current_window;
        int current_ticks = 0;

        std::mt19937 rng;
};


