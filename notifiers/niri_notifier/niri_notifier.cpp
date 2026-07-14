#include "niri_notifier.h"

#include <iostream>

void NiriNotifier::blockNotifier(const std::string& window_title)
{
    std::string command = "notify-send -a Dilimit";
    std::string summary = " \"App blocked\" ";
    std::string body = "\"" + window_title + " reached its time limit" + "\"";
    std::string result = command + summary + body;
    std::cout << result << std::endl;
    std::system(result.c_str());
}