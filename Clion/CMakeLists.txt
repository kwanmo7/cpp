cmake_minimum_required(VERSION 3.28)
project(Clion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
        src/main.cpp
        src/Graph.cpp
        src/main.cpp
)

add_executable(Clion ${SOURCES})