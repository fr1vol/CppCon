cmake_minimum_required(VERSION 3.10)

project(type_erasure)

add_executable(naive naive_solution.cpp)
add_executable(strategy strategy_solution.cpp)
add_executable(morden_v2 morden_solution_v2.cpp)
add_executable(morden_v1 morden_solution.cpp)