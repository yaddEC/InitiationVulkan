#include "Application.h"

Application* Application::instance = nullptr; 

void Application::Create()
{
	instance =new Application();
	instance->vulkan = new Renderer();


}

void Application::Destroy()
{
	instance->vulkan->Destroy();
	instance = nullptr;
}

Application& Application::Get()
{
	
	return *instance;
}

int Application::Run(const std::string& windowName, const int& width, const int& height)
{
	Init(windowName, width, height);

	while (!window->isClosed()) {
		glfwPollEvents();
		//engine->Update();
	}
	Quit();
	return 0;
}


void Application::Quit()
{
	Release();
	Destroy();
	glfwTerminate();
}

bool Application::Init(const std::string windowName, const int& width, const int& height)
{
	if (glfwInit())
	{

		window = Window().Create(windowName, width, height);
		instance->vulkan->setWindow(window->getWindow());
		instance->vulkan->Init();
		
		return true;
	}
	else
	{
		printf("ERREUR D'INIT\n");
		return false;
	}
}


void Application::Release()
{
	engine->Destroy();
	window->Destroy();
}

void Application::Render()
{
}
