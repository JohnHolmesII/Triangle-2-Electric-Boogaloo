#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

#ifdef NDEBUG
const int enableValidationLayers = 0;
#else
const int enableValidationLayers = 1;
#endif

int index()
{
	return 0;
}

int main()
{
	printf("Hello, World!\n");
	return index();
}
