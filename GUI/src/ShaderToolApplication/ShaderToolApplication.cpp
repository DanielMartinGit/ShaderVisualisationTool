#include "ShaderToolApplication.h"

ShaderTool::Application::Application() {}
ShaderTool::Application::~Application() {}

void ShaderTool::Application::InitApp()
{
	InitWindow(1024, 768, "Shader Tool");
	MainApplicationLoop();
}

void ShaderTool::Application::MainApplicationLoop()
{
	while (!glfwWindowShouldClose(&GetCurrentWindow()))
	{
		// Input
		ProcessInput();

		// Update
		Update(0.0f);

		// Render
		Render();

		// Check events and Swap Buffers
		glfwSwapBuffers(&GetCurrentWindow());
		glfwPollEvents();
	}

	DestroyWindow();
}

void ShaderTool::Application::ProcessInput()
{

}

void ShaderTool::Application::Update(float deltaTime)
{

}

void ShaderTool::Application::Render() 
{

}