Triangle 2, Electric Boogaloo
=====

## Dependencies

### Windows
* [MSYS2](http://www.msys2.org/)
* [Cmake 3.10+](https://www.cmake.org/download/)
* [Vulkan SDK](https://vulkan.lunarg.com/sdk/home) (See "Install the SDK" [here](https://vulkan.lunarg.com/doc/sdk/latest/windows/getting_started.html))

### Linux
* Debian & Ubuntu: `sudo apt-get install cmake build-essential libvulkan-dev git`
* Arch: `sudo pacman -S cmake vulkan-validation-layers`

### MacOS
* Apple should fuck itself

## Building on Windows:

1) `git clone https://github.com/JohnHolmesII/Triangle-2-Electric-Boogaloo.git`
2) `cd Triangle-2-Electric-Boogaloo/`
3) `cmake -G "MSYS Makefiles" . && make`
4) `cp 3rdparty/glfw/lib/glfw3.dll .`

## Building on Linux:

1) `git clone https://github.com/JohnHolmesII/Triangle-2-Electric-Boogaloo.git`
2) `cd Triangle-2-Electric-Boogaloo/`
3) `????`
