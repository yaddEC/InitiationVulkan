#pragma once
#include <GLFW/glfw3.h>

class Engine 
{
public:
	Engine() {};
	~Engine() {};
	void Awake();
	void Start();
	void Update();
	void Destroy();
};