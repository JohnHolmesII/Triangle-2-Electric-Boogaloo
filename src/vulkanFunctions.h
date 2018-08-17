#ifndef TRIANGLE_2_ELECTRIC_BOOGALOO_VULKANFUNCTIONS_H
#define TRIANGLE_2_ELECTRIC_BOOGALOO_VULKANFUNCTIONS_H

#include "vulkan/vulkan.h"
#include "types.h"

byt          createInstance(VkInstance);
const char** getRequiredExtensions(u32*);
byt          checkValidationLayerSupport();

#endif //TRIANGLE_2_ELECTRIC_BOOGALOO_VULKANFUNCTIONS_H
