#pragma once

#include <string>
#include <vector>
#include <random>

#include "../../core/active_window.h"

class FakeProvider
{
    public:
        FakeProvider();
        ActiveWindow getActiveWindow();
    private:
        std::vector<ActiveWindow> apps_data;
        ActiveWindow current_window;
        int current_ticks = 0;

        std::mt19937 rng;
};


