if [ -d build ]
then
	rm -rf build/
	mkdir build
else
	mkdir build
fi

cd glfw/
cmake -G "MSYS Makefiles" -DBUILD_SHARED_LIBS=ON -DLIB_SUFFIX=64 -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_DOCS=OFF GLFW_VULKAN_STATIC=OFF . &&
make glfw && cp -f src/glfw3.dll ../build/;

cd ../build;
cmake -G "MSYS Makefiles" ../ && make;

rm -rf CMakeFiles cmake_install.cmake CMakeCache.txt Makefile;
