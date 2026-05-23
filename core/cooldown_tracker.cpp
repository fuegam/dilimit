#include "cooldown_tracker.h"

std::vector<std::string> CooldownTracker::countDown()
{
    std::vector<std::string> unblocked_apps;
    for(auto it = blocked_apps_.begin(); it != blocked_apps_.end();)
    {
        it->second--;

        if(it->second <= 0)
        {
            unblocked_apps.push_back(it->first);
            it = blocked_apps_.erase(it);
        }
        else
            it++;
    }
    return unblocked_apps;
}

void CooldownTracker::blockApp(const std::string& app_id, int cd_time)
{
    blocked_apps_[app_id] = cd_time;
}

bool CooldownTracker::isBlocked(const std::string& app_id)
{
    auto it = blocked_apps_.find(app_id);

    if(it == blocked_apps_.end()) return false;
    return it->second > 0;
}