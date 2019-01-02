config()
{
	
	if [ "$MSYSTEM" = "MSYS" ]; then
		CMAKEGENERATOR="MSYS Makefiles"
	elif command -v ninja >/dev/null; then
		CMAKEGENERATOR="Ninja"
	else
		CMAKEGENERATOR="Unix Makefiles"
	fi

	cmake -G "$CMAKEGENERATOR" ../
}

buildProj()
{
	if [ "$CMAKEGENERATOR" = "Ninja" ]; then
		ninja -j$(nproc)
	else
		make
	fi
}

clean()
{
	cp T2EB ../T2EB
	cd ..
	rm -r build/
}

main()
{
	if [ -d build ]; then
		rm -rf build/
	fi

	mkdir build && cd build
	
	config
	buildProj
	clean
}

main

