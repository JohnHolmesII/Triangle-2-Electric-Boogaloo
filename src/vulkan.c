// Handles all the vulkan initialization and usage functions
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "glfw3.h"
#include "vulkanFunctions.h"

const char* validationLayers = {"VK_LAYER_LUNARG_standard_validation"};

byt    createInstance(VkInstance instance)
{
	if (checkValidationLayerSupport() != CELL_OK) return CELL_FIRE;

	u32                  numExtensions;
	VkApplicationInfo    appInfo    = {};
	VkInstanceCreateInfo createInfo = {};
	const char**         extensions = getRequiredExtensions(&numExtensions);


	appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName   = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName        = "No Engine";
	appInfo.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion         = VK_API_VERSION_1_0;

	createInfo.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo        = &appInfo;
	createInfo.enabledExtensionCount   = numExtensions;
	createInfo.ppEnabledExtensionNames = extensions;
	createInfo.enabledLayerCount       = 0;

	if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS) return CELL_FIRE;

	return CELL_OK;
}

const
char** getRequiredExtensions(u32* numExtensions)
{
	const char** glfwExtensions     = glfwGetRequiredInstanceExtensions(numExtensions);

	return glfwExtensions;
}

byt    checkValidationLayerSupport()
{
	u32                layerCount = 0;
	bln                found      = false;
	VkLayerProperties* availableLayers;
	VkLayerProperties  layerProperties;

	vkEnumerateInstanceLayerProperties(&layerCount, NULL);
	availableLayers = calloc(layerCount, sizeof(VkLayerProperties));
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers);

	for (int i = 0; i < layerCount; ++i)
	{
		layerProperties = availableLayers[i];

		if (!strcmp(validationLayers, layerProperties.layerName))
		{
			found = true;
			break;
		}
	}

	free(availableLayers);

	if (!found) return CELL_FIRE;

	return CELL_OK;
}
