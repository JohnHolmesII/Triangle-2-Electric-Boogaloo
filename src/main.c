#include <vulkan/vulkan.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"


byt initWindow()
{
	return CELL_OK;
}

byt initVulkan()
{
	return CELL_OK;
}

void mainLoop()
{
}

void cleanup()
{
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