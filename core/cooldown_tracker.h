#pragma once

#include <unordered_map>
#include <string>
#include <vector>

class CooldownTracker
{
public:
    std::vector<std::string> countDown();
    void blockApp(const std::string& app_id, int cd_time);
    bool isBlocked(const std::string& app_id);
private:
    std::unordered_map<std::string, int> blocked_apps_; // app_id, remaining time
};