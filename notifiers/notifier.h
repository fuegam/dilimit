#pragma once

#include <string>

class Notifier
{
public:
    virtual void blockNotifier(const std::string& window_title) = 0;
    virtual ~Notifier() = default;
};
