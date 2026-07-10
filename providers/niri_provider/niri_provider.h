#pragma once

#include "../activity_provider.h"

class NiriProvider : public ActivityProvider
{
public:
    ActiveWindow getActiveWindow() override;
private:
    std::string getContent(); // niri msg -j focused-window
    void parseContent(const std::string& content);
    ActiveWindow current_window;
};