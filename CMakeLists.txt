cmake_minimum_required(VERSION 3.0)
project(slave)

find_package(SDL2 REQUIRED)

add_subdirectory(src)
add_subdirectory(master)