#include "fake_blocker.h"

#include <iostream> 

void FakeBlocker::blockActiveWindow(const std::string& window_id)
{
    std::cout << "Blocked " << window_id << std::endl;
    blocked_history_.push_back(window_id);
}

const std::vector<std::string>& FakeBlocker::getBlockerHistory() const
{
    return blocked_history_;
}