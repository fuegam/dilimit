#pragma once

#include "../core/active_window.h"

class ActivityProvider
{
public:
    virtual ActiveWindow getActiveWindow() = 0;
    virtual ~ActivityProvider() = default;
};