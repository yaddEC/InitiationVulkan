#pragma once
#include "Window.h"
#include "Engine.h"
#include "apiVK.h"



class Application
{
private:
	static Application* instance;
	Engine* engine;
	Window* window;
	apiVK* vulkan;

public:
	Application() {};
	~Application() {};
	static void Create();
	static void Destroy();
	static Application& Get();

	int Run(const std::string& windowName, const int& width, const int& height);
	bool Init(const std::string windowName, const int& width, const int& height);
	

	void Quit();
	void Release();
	void Render();
};