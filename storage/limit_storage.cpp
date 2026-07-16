#include "limit_storage.h"

LimitStorage::LimitStorage() : 
    limits{
        {"firefox", {30, 10}},
        {"spotify", {20, 10}},
        {"org.kde.konsole", {20, 10}},
        {"org.telegram.desktop", {20, 10}},
        {"thunar", {10, 10}}
    }
{
}

int LimitStorage::getLimitSeconds(const std::string& window)
{
    return limits[window].limit_seconds;
}

int LimitStorage::getLimitCooldown(const std::string& window)
{
    return limits[window].limit_cooldown;
}
