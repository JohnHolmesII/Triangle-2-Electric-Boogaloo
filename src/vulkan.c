// Handles all the vulkan initialization and usage functions
#include "utils.h"
#include <string.h>
#include "types.h"
#include "glfw3.h"
#include "vulkanFunctions.h"

const char* validationLayers = {"VK_LAYER_LUNARG_standard_validation"};

const
char** getRequiredExtensions(u32* numExtensions)
{
	const char** glfwExtensions     = glfwGetRequiredInstanceExtensions(numExtensions);

	return glfwExtensions;
}

byt    createInstance(VkInstance instance)
{
	if (checkValidationLayerSupport() != CELL_OK)
	{
		return CELL_FIRE;
	}

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

byt    setupDebugCallback(VkDebugUtilsMessengerEXT callback, VkInstance instance)
{
	VkDebugUtilsMessengerCreateInfoEXT createInfo = {};

	createInfo.sType           = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;

	createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
								 VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
								 VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;

	createInfo.messageType     = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT    |
								 VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
								 VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

	createInfo.pfnUserCallback = debugCallback;

	if (CreateDebugUtilsMessengerEXT(instance, &createInfo, NULL, &callback) != VK_SUCCESS)
	{
		warn("failed to set up debug callback!");
	}

	return CELL_OK;
}

VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
											 VkDebugUtilsMessageTypeFlagsEXT             messageType,
											 const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
											 void*                                       pUserData)
{
	warn(pCallbackData->pMessage);

	return VK_FALSE;
}

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pCallback)
{
	PFN_vkCreateDebugUtilsMessengerEXT func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");

	if (func != NULL)
	{
		return func(instance, pCreateInfo, pAllocator, pCallback);
	}
	else
	{
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}
