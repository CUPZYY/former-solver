cmake_minimum_required(VERSION 3.30)
project(former_solver)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(former_solver
        src/util/FileParser.cpp
        src/Game.cpp
        src/main.cpp
        src/solve/MCTS.cpp
        include/MCTS.h)

file(COPY input.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

