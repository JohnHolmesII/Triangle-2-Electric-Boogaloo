cmake_minimum_required(VERSION 3.10)
project(Triangle_2__Electric_Boogaloo C)

set(CMAKE_C_FLAGS "-Wall -std=c11")
set(3RDPARTY ${PROJECT_SOURCE_DIR}/3rdparty)

include_directories("${PROJECT_SOURCE_DIR}")

find_package(PkgConfig) # Find dependencies

if (PKGCONFIG_FOUND AND UNIX)
    pkg_search_module(GLFW REQUIRED glfw3)
    if (GLFW_FOUND)
        # Try to use the system GLFW headers
        include_directories("/usr/include/GLFW/")
        link_libraries(${GLFW_LIBRARIES})
    endif()
elseif (WIN32)
    link_directories("${3RDPARTY}/glfw/lib/")
    link_libraries("glfw3.dll")
endif()

include_directories("${3RDPARTY}/glfw/include/")

find_package(Vulkan)
if (VULKAN_FOUND)
    include_directories(${Vulkan_INCLUDE_DIRS})
    link_libraries(${Vulkan_LIBRARIES})
elseif(WIN32)
    include_directories("$ENV{VULKAN_SDK}/Include/")
    link_directories("$ENV{VULKAN_SDK}/Lib/")
    link_libraries("vulkan-1.lib")
endif()

add_executable(T2EB src/main.c src/vulkan src/vulkanFunctions.h src/types.h)
