#include "limit_storage.h"

LimitStorage::LimitStorage() : 
    limits{
        {"firefox", 30},
        {"spotify", 20},
        {"org.kde.konsole", 10},
        {"org.telegram.desktop", 8}
    }
{
}

int LimitStorage::getLimitSeconds(const std::string& window)
{
    return limits[window];
}