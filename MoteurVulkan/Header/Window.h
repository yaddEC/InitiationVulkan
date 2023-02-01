#pragma once
#include <string>

class Window
{
private:
	std::string windowName;
	int width;
	int height;
public:
	Window() {};
	~Window() {};
	Window* Create(const std::string&windowName,int clientWidth,int clientHeight);
	void Destroy();
};