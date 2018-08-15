cmake_minimum_required(VERSION 3.12)
project(Triangle_2__Electric_Boogaloo C)

set(CMAKE_C_FLAGS "-Wall -std=c11")
set(GLFW "${PROJECT_SOURCE_DIR}/3rdparty/glfw/include/glfw3.h")

configure_file ("${PROJECT_SOURCE_DIR}/src/config.h.in" "${PROJECT_SOURCE_DIR}/src/config.h")

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("$ENV{VULKAN_SDK}/Include/")
include_directories("/3rdparty/glfw/include/")

link_directories("$ENV{VULKAN_SDK}/Lib/")
link_directories("${PROJECT_SOURCE_DIR}/glfw/lib/")

link_libraries("vulkan-1.lib")
link_libraries("glfw3.dll")

add_executable(Triangle_2__Electric_Boogaloo src/main.c src/types.h src/config.h)
