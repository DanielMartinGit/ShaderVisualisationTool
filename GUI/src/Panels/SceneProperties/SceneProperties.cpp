#include "SceneProperties.h"

Panels::SceneProperties::SceneProperties()
{
	m_VertexShaderPath = "";
	m_FragmentShaderPath = "";
}
Panels::SceneProperties::~SceneProperties() {}

void Panels::SceneProperties::OnImGuiRender()
{
	ImGui::Begin("Scene Properties", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	ImGui::Text("Vertex");
	ImGui::SameLine();
	ImGui::InputText("##VertexShaderFilePath", &m_VertexShaderPath);
	ImGui::SameLine();
	
	if (ImGui::Button("Choose Vertex", m_ButtonSize))
	{
		std::vector<std::string> filter = { "Vertex Files", "*.vert" };
		Utils::FileDialog::OpenFile("Select Vertex Shader File", ".", m_VertexShaderPath, filter, pfd::opt::none);
	}

	ImGui::Text("Fragment");
	ImGui::SameLine();
	ImGui::InputText("##FragmentShaderFilePath", &m_FragmentShaderPath);
	ImGui::SameLine();

	if (ImGui::Button("Choose Fragment", m_ButtonSize))
	{
		std::vector<std::string> filter = {"Fragment Files", "*.frag"};
		Utils::FileDialog::OpenFile("Select Fragment Shader File", ".", m_FragmentShaderPath, filter, pfd::opt::none);
	}

	if (ImGui::Button("Link", m_ButtonSize))
	{
		Framework::Shader vert = Framework::Shader(m_VertexShaderPath.c_str(), GL_VERTEX_SHADER);
		Framework::Shader frag = Framework::Shader(m_FragmentShaderPath.c_str(), GL_FRAGMENT_SHADER);

		Framework::Scene::GetShaderProgram().ClearProgram();
		Framework::Scene::GetShaderProgram().CreateShader(vert);
		Framework::Scene::GetShaderProgram().CreateShader(frag);
		Framework::Scene::GetShaderProgram().Link();
	}

	ImGui::End();
}