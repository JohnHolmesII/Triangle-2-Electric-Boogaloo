// Handles all the vulkan initialization and usage functions
#include "types.h"
#include "glfw3.h"
#include "vulkanFunctions.h"

bln createInstance(VkInstance instance)
{
	VkApplicationInfo    appInfo    = {};
	VkInstanceCreateInfo createInfo = {};
	u32                  numExtensions;
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

const char** getRequiredExtensions(u32* numExtensions)
{
	const char** glfwExtensions     = glfwGetRequiredInstanceExtensions(numExtensions);

	return glfwExtensions;
}
