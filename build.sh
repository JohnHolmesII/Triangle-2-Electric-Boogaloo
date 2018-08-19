if [ -d build ]
then
	rm -rf build/
	mkdir build
else
	mkdir build
fi

cd build

CMAKEGENERATOR="Unix Makefiles"
if [ -n "$MSYSTEM" ]; then
	CMAKEGENERATOR="MSYS Makefiles"
elif command -v ninja >/dev/null; then
	CMAKEGENERATOR="Ninja"
fi

cmake -G "$CMAKEGENERATOR" ../

if [ "$CMAKEGENERATOR" = "Ninja" ]; then
	ninja
else
	make
fi

rm -rf CMakeFiles cmake_install.cmake CMakeCache.txt Makefile
