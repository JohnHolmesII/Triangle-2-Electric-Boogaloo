#define GLFW_INCLUDE_VULKAN
#include <glfw3.h>

#include <vulkan/vulkan.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

#define WIDTH 800
#define HEIGHT 600
#define TITLE "Triangle 2: Electric Boogaloo"

GLFWwindow* window = NULL;

byt initWindow()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

	return CELL_OK;
}

byt initVulkan()
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