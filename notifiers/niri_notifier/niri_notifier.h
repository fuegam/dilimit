#pragma once

#include "../notifier.h" 

#include <string>

class NiriNotifier : public Notifier
{
public:
    void blockNotifier(const std::string& window_title) override;
};