#include "dilimit_app.h"

#include "../providers/fake_provider/fake_provider.h"
#include "../providers/niri_provider/niri_provider.h"
#include "../providers/activity_provider.h"

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    NiriProvider provider;
    LimitStorage limits;
    DilimitApp dilimit_app(provider, limits);

    dilimit_app.run();

    return 0;
}
