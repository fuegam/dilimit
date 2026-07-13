#pragma once

#include <string>
#include <vector>

#include "../window_blocker.h"

class NiriBlocker : public WindowBlocker
{
public:
    void blockActiveWindow(const std::string& window_id) override;
private:
    std::string getContent(); // niri msg -j windows
    std::vector<int> parseContent(const std::string& content, const std::string& target_id);
};