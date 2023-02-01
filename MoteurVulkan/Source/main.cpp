#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "imgui.h"

#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#ifdef _DEBUG
#define IMGUI_VULKAN_DEBUG_REPORT
#endif
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include "Application.h"

int main() {
  /*  glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();*/
    Application::Create();
    Application app = Application::Get();
    
    app.Run("VulkanMoteur", 200, 200);

    return 0;
}