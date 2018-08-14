cmake_minimum_required(VERSION 3.12)
project(Triangle_2__Electric_Boogaloo C)

set(CMAKE_C_FLAGS "-Wall --std=c11")

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("/glfw/include/")
include_directories("${CMAKE_SYSTEM_INCLUDE_PATH}/Include/")

link_directories("${CMAKE_SYSTEM_INCLUDE_PATH}/Lib/")
link_directories("${PROJECT_SOURCE_DIR}/glfw/")

add_executable(Triangle_2__Electric_Boogaloo src/main.c src/types.h)

link_libraries("vulkan-1.lib")
link_libraries("glfw3.lib")

