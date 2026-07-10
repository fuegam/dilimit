#include "niri_provider.h"

#include <iostream>
#include <cstdio>
#include <nlohmann/json.hpp>

std::string NiriProvider::getContent()
{
    std::string command = "niri msg -j focused-window";

    FILE* pipe = popen(command.c_str(), "r");
    if(!pipe)
    {
        std::cout << "Error" << std::endl;
        return "";
    }

    char buff[128];
    std::string result = "";
    while(fgets(buff, sizeof(buff), pipe) != nullptr)
    {
        result += buff;
    }

    pclose(pipe);

    return result;
}

void NiriProvider::parseContent(const std::string& content)
{
    try
    {
        nlohmann::json data = nlohmann::json::parse(content);

        if(data.is_null()) 
        {
            current_window = {"", ""};
            return; 
        }

        std::string window_id = data["app_id"];
        std::string window_title = data["title"];

        current_window = {window_id, window_title};
    }
    catch(const nlohmann::json::parse_error& e)
    {
        std::cerr << "Error occured while parsing JSON: " << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

ActiveWindow NiriProvider::getActiveWindow()
{
    parseContent(getContent());
    return current_window;
}