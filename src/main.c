#define GLFW_INCLUDE_VULKAN

#include "src/config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "vulkan/vulkan.h"
#include GLFW

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

		if (!window) return CELL_FIRE;
	}
	else
	{
		return CELL_FIRE;
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

void cleanup()
{

}

int main()
{
	if (initWindow() != CELL_OK) return CELL_FIRE;
	if (initVulkan() != CELL_OK) return CELL_FIRE;

	mainLoop();
	cleanup();

	return CELL_OK;
}
