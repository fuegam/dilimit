#include "niri_notifier.h"

#include <iostream>

std::string NiriNotifier::capitalizeFirst(const std::string& s)
{
    std::string s1 = s;
    s1[0] = std::toupper(s1[0]);
    return s1;
}

void NiriNotifier::blockNotifier(const std::string& window_id)
{
    std::string window_id_upper;
    window_id_upper = capitalizeFirst(window_id);

    std::string command = "notify-send -a Dilimit";
    std::string summary = " \"App blocked\" ";
    std::string body = "\"" + window_id_upper + " reached its time limit" + "\"";
    std::string result = command + summary + body;
    std::cout << result << std::endl;
    std::system(result.c_str());
}