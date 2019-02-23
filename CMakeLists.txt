cmake_minimum_required(VERSION 3.5.1)
project(T2EB C)

set(CMAKE_C_FLAGS "-Wall -Wextra -std=c11")
set(3RDPARTY ${PROJECT_SOURCE_DIR}/3rdparty)

include_directories("${PROJECT_SOURCE_DIR}")

include_directories("${3RDPARTY}/cglm/include/cglm/")

find_package(Vulkan)
if (VULKAN_FOUND)
    include_directories(${Vulkan_INCLUDE_DIRS})
    link_libraries(${Vulkan_LIBRARIES})
elseif(WIN32)
    include_directories("$ENV{VULKAN_SDK}/Include/")
    link_directories("$ENV{VULKAN_SDK}/Lib/")
    link_libraries("vulkan-1.lib")
endif()

add_executable(T2EB src/main.c src/types.h src/utils.c src/utils.h)
