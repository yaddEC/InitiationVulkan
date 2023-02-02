#pragma once
#include "vulkan/vulkan.h"
#include <GLFW/glfw3.h>
#include <optional>

#define GLFW_INCLUDE_VULKAN

#include "Debug.h"

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete() {
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};

class Renderer
{
private:
	VkInstance VulkInstance;
	Debug* debug;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;
	VkQueue graphicsQueue;
	VkSurfaceKHR surface;
	GLFWwindow* window;

public:
	Renderer() {};
	~Renderer() {};
	void setWindow(GLFWwindow* windowSetter);
	void Init();
	void Destroy();

	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);
	void createSurface();
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	
	void createLogicalDevice();
	
};