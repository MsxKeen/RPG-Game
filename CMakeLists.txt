cmake_minimum_required(VERSION 3.29)
project(RPG_Game)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(RPG_Game main.cpp
        Player.h
        Player.cpp
        Skeleton.cpp
        Skeleton.h
        Math.cpp
        Math.h
        FrameRates.cpp
        FrameRates.h
        Bullet.cpp
        Bullet.h
)
target_link_libraries(RPG_Game sfml-graphics)
