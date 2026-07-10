#pragma once

#include <string>

class WindowBlocker
{
public:
    virtual void blockActiveWindow(const std::string& window_id) = 0;
    virtual ~WindowBlocker() = default;
};