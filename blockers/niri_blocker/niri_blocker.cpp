#include <iostream>

#include <nlohmann/json.hpp>
#include "niri_blocker.h"

std::string NiriBlocker::getContent()
{
    std::string command = "niri msg -j windows";

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

std::vector<int> NiriBlocker::parseContent(const std::string& content, const std::string& target_id)
{
    try
    {
        nlohmann::json data = nlohmann::json::parse(content);

        std::vector<int> to_block;
        for(const auto& window : data)
        {
            if(window["app_id"] == target_id) 
                to_block.push_back(window["id"]);
        }
        return to_block;
    }
    catch(const nlohmann::json::parse_error& e)
    {
        std::cerr << "Error occured while parsing JSON: " << e.what() << std::endl;
        return {};
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

void NiriBlocker::blockActiveWindow(const std::string& window_id)
{
    std::vector<int> to_block = parseContent(getContent(), window_id);
    for(auto item : to_block)
    {
        std::string cmd = "niri msg action close-window --id " + std::to_string(item);
        std::system(cmd.c_str());
    }
}