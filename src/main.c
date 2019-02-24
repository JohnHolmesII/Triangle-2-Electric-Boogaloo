#define GLFW_INCLUDE_VULKAN

#include <glfw3.h>
#include <vulkan/vulkan.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "utils.h"

#define WIDTH  800
#define HEIGHT 600
#define TITLE  "Triangle 2: Electric Boogaloo"

GLFWwindow* window   = NULL;
VkInstance  instance = NULL;

void checkExtensions(const char** required, u32 numReq)
{
	int                    numFound   = 0;
	bool                   found      = false;
	u32                    numExts    = 0;
	VkExtensionProperties* extensions = NULL;

	vkEnumerateInstanceExtensionProperties(NULL, &numExts, NULL);
	extensions = malloc(numExts * sizeof(VkExtensionProperties));
	vkEnumerateInstanceExtensionProperties(NULL, &numExts, extensions);

	for (int i = 0; i < numReq; ++i)
	{
		for (int j = 0; !found && j < numExts; ++j)
		{
			if (!strcmp(required[i], extensions[j].extensionName))
			{
				found = true;
				++numFound;
				printf("\t%s - FOUND\n", required[i]);
			}
		}

		if (!found)
		{
			printf("Missing required extension: %s\n", required[i]);
			err("Fatal, likely drivers.");
		}
	}

	free(extensions);
}

void createInstance()
{
	u32                  glfwExtensionCount = 0;
	const char**         glfwExtensions     = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	VkApplicationInfo    appInfo            = {};
	VkInstanceCreateInfo createInfo         = {};

	checkExtensions(glfwExtensions, glfwExtensionCount);

	appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName   = "T2EB";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName        = "Triangle Engine";
	appInfo.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion         = VK_API_VERSION_1_1;

	createInfo.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo        = &appInfo;
	createInfo.enabledExtensionCount   = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount       = 0;

	if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS)
	{ err("Failed to make Vulkan instance"); }
}

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
	createInstance();

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
	if (initWindow() != CELL_OK)
	{ err("Could not init glfw WM, exiting"); }

	printf("Initializing vulkan\n");
	if (initVulkan() != CELL_OK)
	{ err("Could not init Vulkan, exiting"); }

	printf("Begin main loop\n");
	mainLoop();

	printf("Cleanup and leave\n");
	cleanup();

	return CELL_OK;
}