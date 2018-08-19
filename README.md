Triangle 2, Electric Boogaloo
=====

[![Build status](https://ci.appveyor.com/api/projects/status/r7koaqho74vf179p?svg=true)](https://ci.appveyor.com/project/JohnHolmesII/triangle-2-electric-boogaloo)

## Dependencies

### Windows
* [MSYS2](http://www.msys2.org/)
* [Cmake 3.10+](https://www.cmake.org/download/)
* [Vulkan SDK](https://vulkan.lunarg.com/sdk/home) (See "Install the SDK" [here](https://vulkan.lunarg.com/doc/sdk/latest/windows/getting_started.html))

### Linux
* Ubuntu: `sudo apt-get install cmake build-essential libvulkan-dev libxi-dev libxrandr-dev libxinerama-dev libxcursor-dev libgl1-mesa-dev git`
* Arch:   `sudo pacman -S cmake vulkan-validation-layers`

### MacOS
* Apple should fuck itself

## Building:
*Windows users must build using MSYS2*

1) `git clone --recurse-submodules https://github.com/JohnHolmesII/Triangle-2-Electric-Boogaloo.git`
2) `cd Triangle-2-Electric-Boogaloo/`
3) `./build.sh`
