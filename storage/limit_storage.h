#pragma once

#include <map>
#include <string>

class LimitStorage
{
public:
    LimitStorage();
    int getLimitSeconds(const std::string& window);
private:
    std::map<std::string, int> limits;
};

