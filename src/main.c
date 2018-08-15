#define GLFW_INCLUDE_VULKAN

#include <C:\Users\God\Programs\Triangle 2, Electric Boogaloo\glfw\include\glfw3.h>
#include <vulkan/vulkan.h>
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

bln initWindow()
{
	if (glfwInit())
	{
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL);

		if (!window) return error;
	}
	else
	{

		return error;
	}

	return CELL_OK;
}

bln initVulkan()
{
	return CELL_OK;
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
	bln status = CELL_OK;

	status = initWindow();
	initVulkan();
	mainLoop();
	//cleanup();

	return status;
}

int main()
{
	if (run() != CELL_OK)
	{
		return error;
	}

	return CELL_OK;
}
