#include "ShaderToolApplication.h"

ShaderTool::Application::Application() {}
ShaderTool::Application::~Application() {}

void ShaderTool::Application::InitApp()
{
	InitWindow(1024, 768, "Shader Tool");

	m_PanelManager.AddPanel("Viewport", &m_Viewport);

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
	m_Scene.Update(deltaTime);
}

void ShaderTool::Application::Render() 
{
	BeginFrame();
	m_Scene.Render();
	m_PanelManager.RenderActivePanels();
	EndFrame();
}