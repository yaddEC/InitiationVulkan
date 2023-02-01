#pragma once
#include "vulkan/vulkan.h"
#include <GLFW/glfw3.h>
#include <vector>
#define DEBUG
#ifdef DEBUG
const bool enableValidationLayers = true;
#else
const bool enableValidationLayers = false;
#endif

class apiVK
{
private:
	VkInstance VulkInstance;
	VkDebugUtilsMessengerEXT debugMessenger;
	const std::vector<const char*> 	validationLayers = {
	"VK_LAYER_KHRONOS_validation"
	};

public:
	apiVK() {};
	~apiVK() {};
	void Init();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	void Destroy();
	void setupDebugMessenger();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	
};