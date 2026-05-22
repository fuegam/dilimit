#include "fake_provider.h"

FakeProvider::FakeProvider() :
    apps_data{
        {"firefox", "YouTube - Mozilla Firefox"},
        {"org.telegram.desktop", "Telegram"},
        {"org.kde.konsole", "~/projects/dilimit"},
        {"code", "dilimit - Visual Studio Code"},
        {"spotify", "Liked Songs - Spotify"}
    },
    rng(std::random_device{}())
{
}

ActiveWindow FakeProvider::getActiveWindow()
{
    std::uniform_int_distribution<std::size_t> windowDist(0, apps_data.size() - 1);
    std::uniform_int_distribution<int> ticksDist(3, 7);

    if(current_ticks == 0)
    {
        current_ticks = ticksDist(rng);
        int idx(windowDist(rng));

        current_window = apps_data[idx];
        return current_window;
    }

    
    current_ticks--;
    return current_window;
}