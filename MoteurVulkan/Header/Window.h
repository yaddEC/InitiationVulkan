#pragma once
#include <string>
#include <GLFW/glfw3.h>

class Window
{
private:
	std::string windowName;
	int width;
	int height;
	GLFWwindow* window;
public:
	Window() {};
	~Window() {};
	Window* Create(const std::string&windowName,const int& clientWidth, const int& clientHeight);
	void Destroy();
	bool isClosed();
	GLFWwindow* getWindow();
};