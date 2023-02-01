#pragma once
#include "Window.h"
#include "Engine.h"

class Application
{
private:
	static Application* instance;
	Engine engine;
	Window window;

public:
	Application() {};
	~Application() {};
	void Create();
	void Destroy();
	static Application& Get();
	int Run(const std::string& windowName, int width, int height);
	void Quit();
	bool Init(const std::string windowName, int width, int height);
	void Release();
	void Render();
};