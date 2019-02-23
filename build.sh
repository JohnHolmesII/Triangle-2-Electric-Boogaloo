msg='[unknown]'

die()
{
	printf "Build failed during %s" "$msg"
	exit 1
}

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

	if [ $? != 0 ]; then
		printf "[%d]" $?
		msg="configuration, cmake error."
		die
	fi
}

buildProj()
{
	if [ "$CMAKEGENERATOR" = "Ninja" ]; then
		ninja

		if [ $? != 0 ]; then
			msg='main T2EB build, Ninja error.'
			die
		fi
	else
		make -j$(nproc)

		if [ $? != 0 ]; then
			msg='main T2EB build, make error.'
			die
		fi
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

