cmake_minimum_required(VERSION 3.16)

project(dilimit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dilimit
    core/main.cpp
    core/usage_tracker.cpp
    storage/limit_storage.cpp
    providers/fake_provider/fake_provider.cpp
)

target_include_directories(dilimit PRIVATE
    core
    storage
    providers/fake_provider
)