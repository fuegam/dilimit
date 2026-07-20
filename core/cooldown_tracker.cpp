#include "cooldown_tracker.h"

bool CooldownTracker::isExpired(TimePoint t) const
{
    return std::chrono::system_clock::now() >= t;
}

std::vector<std::string> CooldownTracker::countDown()
{
    std::vector<std::string> unblocked_apps;
    for(auto it = blocked_apps_.begin(); it != blocked_apps_.end();)
    {
        if(isExpired(it->second))
        {
            unblocked_apps.push_back(it->first);
            it = blocked_apps_.erase(it);
        }
        else
            it++;
    }
    return unblocked_apps;
}

void CooldownTracker::blockApp(const std::string& app_id, TimePoint expires_at)
{
    blocked_apps_[app_id] = expires_at;
}

bool CooldownTracker::isBlocked(const std::string& app_id) const
{
    auto it = blocked_apps_.find(app_id);

    if(it == blocked_apps_.end()) return false;
    return !isExpired(it->second);
}