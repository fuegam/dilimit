cmake_minimum_required(VERSION 3.16)

project(dilimit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(json)

add_executable(dilimit
    core/main.cpp
    core/dilimit_app.cpp
    core/usage_tracker.cpp
    core/cooldown_tracker.cpp
    storage/limit_storage.cpp
    blockers/fake_blocker/fake_blocker.cpp
    providers/fake_provider/fake_provider.cpp
    blockers/niri_blocker/niri_blocker.cpp
    providers/niri_provider/niri_provider.cpp
)

target_compile_options(dilimit PRIVATE -Wall -Wextra)

target_include_directories(dilimit PRIVATE
    core
    storage
    providers
    blockers
)

target_link_libraries(dilimit PRIVATE nlohmann_json::nlohmann_json)