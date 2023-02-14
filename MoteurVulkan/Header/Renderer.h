#pragma once
#include "vulkan/vulkan.h"
#include <GLFW/glfw3.h>
#include <string>
#include <set>
#include <cstdint> 
#include <limits> 
#include <algorithm> 
#include <fstream>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <chrono>
#include "VertexBuffer.h"

#define GLFW_INCLUDE_VULKAN

#include "Debug.h"

const int MAX_FRAMES_IN_FLIGHT = 2;


class Renderer
{
private:
	VkInstance VulkInstance;
	Debug* debug;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;

	VkQueue graphicsQueue;
	VkQueue presentQueue;

	VkSurfaceKHR surface;

	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;

	VkRenderPass renderPass;

	VkPipeline graphicsPipeline;
	VkPipelineLayout pipelineLayout;
	VkDescriptorSetLayout descriptorSetLayout;

	VkCommandPool commandPool;
	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;
	VkBuffer indexBuffer;
	VkDeviceMemory indexBufferMemory;

	std::vector<VkCommandBuffer> commandBuffers;

	VkDescriptorPool descriptorPool;
	std::vector<VkDescriptorSet> descriptorSets;

	VkFence inFlightFence;
	std::vector<VkFramebuffer> swapChainFramebuffers;
	std::vector<VkImageView> swapChainImageViews;

	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkFence> inFlightFences;

	std::vector<VkBuffer> uniformBuffers;
	std::vector<VkDeviceMemory> uniformBuffersMemory;
	std::vector<void*> uniformBuffersMapped;

	GLFWwindow* window;
	const std::vector<const char*> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
	uint32_t currentFrame = 0;
public:
	bool framebufferResized = false;
public:
	Renderer() {};
	~Renderer() {};
	void setWindow(GLFWwindow* windowSetter);
	void Init();
	void Destroy();
	void pickPhysicalDevice();

	
	void createInstance();
	void createSwapChain();
	void createLogicalDevice();
	void createSurface();
	void createImageViews();
	void createRenderPass();
	void createGraphicsPipeline();
	void createFramebuffers();
	void createCommandPool();
	void createCommandBuffer();
	void createSyncObjects();
	void createVertexBuffer();
	void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
	void createIndexBuffer();
	void createDescriptorSetLayout();
	void createUniformBuffers();
	void createDescriptorPool();
	void createDescriptorSets();

	void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

	void drawFrame();
	void stopDraw();

	void cleanupSwapChain();
	void recreateSwapChain();

	void updateUniformBuffer(uint32_t currentImage);

	bool isDeviceSuitable(VkPhysicalDevice device);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);

	static std::vector<char> readFile(const std::string& filename);
	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
	void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
	VkShaderModule createShaderModule(const std::vector<char>& code);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	
	
};