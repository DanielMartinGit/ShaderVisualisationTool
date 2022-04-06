#include "ShaderToolApplication.h"

ShaderTool::Application::Application() {}
ShaderTool::Application::~Application() {}

void ShaderTool::Application::InitApp()
{
	InitWindow(1700, 768, "Shader Tool");

	m_PanelManager.AddPanel("Viewport", &m_Viewport);
	m_PanelManager.AddPanel("Resources", &m_Resources);
	m_PanelManager.AddPanel("Console", &m_Console);
	m_PanelManager.AddPanel("Scene Properties", &m_SceneProperties);
	m_PanelManager.AddPanel("Script Editor", &m_ScriptEditor);

	m_Scene.InitScene();
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
	m_Resources.SetLoadedShaderCount(m_Scene.GetShaderProgram().GetShadersLoaded());
	m_Scene.Update(deltaTime);
}

void ShaderTool::Application::Render() 
{
	BeginFrame();
	ImGui::Begin("Editor", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDocking);

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;
	ImVec2 vPos0 = ImGui::GetMainViewport()->Pos;

	ImGui::SetWindowPos(ImVec2((float)vPos0.x, (float)vPos0.y), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);
	ImGui::PopStyleVar();
	
	m_DockSpaceID = ImGui::GetID("DockSpace");
	ImGui::DockSpace(m_DockSpaceID, ImVec2(0.f, 0.f), ImGuiDockNodeFlags_None | ImGuiDockNodeFlags_PassthruCentralNode);
	
	m_Scene.Render();
	m_PanelManager.RenderActivePanels();

	ImGui::End();
	EndFrame();
}