Triangle 2, Electric Boogaloo
=====

[![Build status](https://ci.appveyor.com/api/projects/status/r7koaqho74vf179p?svg=true)](https://ci.appveyor.com/project/JohnHolmesII/triangle-2-electric-boogaloo)

## Dependencies

### Windows

*WSL and Visual Studio are not currently supported as build platforms. CLion is preferred, using the MinGW toolchain.*

* [MSYS2](http://www.msys2.org/)
* [Vulkan SDK](https://vulkan.lunarg.com/sdk/home) (See "Install the SDK" [here](https://vulkan.lunarg.com/doc/sdk/latest/windows/getting_started.html))

In MSYS2 run `pacman -S mingw-w64-x86_64-toolchain`. You should use most of that already.

### Linux
* Ubuntu: `sudo apt install cmake build-essential libvulkan-dev libxi-dev libxrandr-dev libxinerama-dev libxcursor-dev libgl1-mesa-dev git`
* Arch:   `sudo pacman -S cmake vulkan-validation-layers`

### MacOS
* Apple should fuck itself

## Building:

1) `git clone --recurse-submodules https://github.com/JohnHolmesII/Triangle-2-Electric-Boogaloo.git`
2) `cd Triangle-2-Electric-Boogaloo/`
3) `./build.sh`
