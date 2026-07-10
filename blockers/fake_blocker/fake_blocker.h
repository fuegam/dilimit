#pragma once

#include <vector>

#include "../window_blocker.h"

class FakeBlocker : public WindowBlocker
{
public:
    void blockActiveWindow(const std::string& window_id) override;
    const std::vector<std::string>& getBlockerHistory() const;
private:
    std::vector<std::string> blocked_history_;
};