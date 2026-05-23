#pragma once

#include "limit_rule.h"

#include <map>
#include <string>

class LimitStorage
{
public:
    LimitStorage();
    int getLimitSeconds(const std::string& window);
    int getLimitCooldown(const std::string& window);
private:
    std::map<std::string, LimitRule> limits;
};
