#define GLFW_INCLUDE_VULKAN

#include <C:\Users\God\Programs\Triangle 2, Electric Boogaloo\glfw\include\glfw3.h>
//#include <vulkan/vulkan.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

#ifdef NDEBUG
const int enableValidationLayers = 0;
#else
const int enableValidationLayers = 1;
#endif

const u16 WIDTH  = 800;
const u16 HEIGHT = 600;

GLFWwindow* window;

void initWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL);
}

void mainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

}

bln run()
{
	initWindow();
	//initVulkan();
	//mainLoop();
	//cleanup();
	return 0;
}

int main()
{
	if (run() != 0)
	{
		return -1;
	}

	return 0;
}
