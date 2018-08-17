#define GLFW_INCLUDE_VULKAN

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "glfw3.h"
#include "vulkanFunctions.h"

#ifdef NDEBUG
const int enableValidationLayers = 0;
#else
const int enableValidationLayers = 1;
#endif

const u16   WIDTH            = 800;
const u16   HEIGHT           = 600;

GLFWwindow* window;
VkInstance  instance;

byt initWindow()
{
	if (glfwInit())
	{
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL);

		if (!window) return CELL_FIRE;
	}
	else
	{
		return CELL_FIRE;
	}

	return CELL_OK;
}

byt initVulkan()
{
	if (createInstance(instance) != CELL_OK) return CELL_FIRE;

	return CELL_OK;
}

void mainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}

void cleanup()
{
	vkDestroyInstance(instance, NULL);
	glfwDestroyWindow(window);
	glfwTerminate();
}

int main()
{
	printf("Initializing glfw window manager\n");
	if (initWindow() != CELL_OK) return CELL_FIRE;

	printf("Initializing vulkan\n");
	if (initVulkan() != CELL_OK) return CELL_FIRE;

	printf("Begin main loop\n");
	mainLoop();

	printf("Cleanup and leave\n");
	cleanup();

	return CELL_OK;
}
