#ifndef TRIANGLE_2_ELECTRIC_BOOGALOO_VULKANFUNCTIONS_H
#define TRIANGLE_2_ELECTRIC_BOOGALOO_VULKANFUNCTIONS_H

#include "vulkan/vulkan.h"
#include "types.h"

const
char**   getRequiredExtensions(u32*);
byt      createInstance(VkInstance);
byt      checkValidationLayerSupport();
byt      setupDebugCallback(VkDebugUtilsMessengerEXT, VkInstance);
VkResult CreateDebugUtilsMessengerEXT(VkInstance, const VkDebugUtilsMessengerCreateInfoEXT*, const VkAllocationCallbacks*, VkDebugUtilsMessengerEXT*);

VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT,
											 VkDebugUtilsMessageTypeFlagsEXT,
											 const VkDebugUtilsMessengerCallbackDataEXT*,
											 void*);

#endif //TRIANGLE_2_ELECTRIC_BOOGALOO_VULKANFUNCTIONS_H
