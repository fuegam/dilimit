#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <chrono>

class CooldownTracker
{
public:
    using TimePoint = std::chrono::system_clock::time_point;

    std::vector<std::string> countDown();
    void blockApp(const std::string& app_id, TimePoint expires_at);
    bool isBlocked(const std::string& app_id) const;
private:
    bool isExpired(TimePoint t) const;
    std::unordered_map<std::string, TimePoint> blocked_apps_;
};