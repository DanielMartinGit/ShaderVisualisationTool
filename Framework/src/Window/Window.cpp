#include "Window.h"

Framework::Window::Window() {}
Framework::Window::~Window() {}

void Framework::Window::InitWindow(uint32_t width, uint32_t height, const char* title)
{
	Framework::Init::InitOpenGL();
	m_Window = Framework::Init::InitWindow(1024, 768, "Shader Tool");
	Framework::Init::InitGLAD();
	Framework::Init::InitImGui(m_Window, m_GLSLVersion);
}

void Framework::Window::BeginFrame()
{
	// Clear the screen for the next frame
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Create a new frame for ImGui
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Framework::Window::EndFrame()
{
	// Render ImGui
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Framework::Window::DestroyWindow()
{
	// Shutdown ImGui and destroy the GLFW window, then terminate GLFW altogether
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// Destroy the Window and Terminate GLFW
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void Framework::Window::ProcessInput() {}
void Framework::Window::Update(float deltaTime) {}
void Framework::Window::Render() {}