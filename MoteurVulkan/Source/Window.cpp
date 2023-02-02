#include "Window.h"



Window* Window::Create(const std::string& windowname, const int& clientWidth, const int& clientHeight)
{

	windowName = windowname;
	width = clientWidth;
	height = clientHeight;
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	return this;
}

void Window::Destroy()
{
	//glfwDestroyWindow(window);
}

bool Window::isClosed()
{
	return glfwWindowShouldClose(window);
}

GLFWwindow* Window::getWindow()
{
	return window;
}
