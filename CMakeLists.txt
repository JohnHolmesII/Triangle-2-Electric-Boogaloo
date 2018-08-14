cmake_minimum_required(VERSION 3.12)
project(Triangle_2__Electric_Boogaloo C)

set(CMAKE_C_FLAGS "-Wall -std=c99")

include_directories("$PATH")

add_executable(Triangle_2__Electric_Boogaloo main.c types.h)
