#include "SceneProperties.h"

Panels::SceneProperties::SceneProperties()
{
	m_VertexShaderPath = "";
	m_FragmentShaderPath = "";
	m_ComputeShaderPath = "";
}
Panels::SceneProperties::~SceneProperties() {}

void Panels::SceneProperties::OnImGuiRender()
{
	ImGui::Begin("Scene Properties", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	ImGui::Text("Vert");
	ImGui::SameLine();
	ImGui::InputText("##VertexShaderFilePath", &m_VertexShaderPath);
	ImGui::SameLine();
	
	if (ImGui::Button("Choose Vertex", m_ButtonSize))
	{
		std::vector<std::string> filter = { "Vertex Files", "*.vert" };
		Utils::FileDialog::OpenFile("Select Vertex Shader File", ".", m_VertexShaderPath, filter, pfd::opt::none);
	}

	ImGui::Text("Frag");
	ImGui::SameLine();
	ImGui::InputText("##FragmentShaderFilePath", &m_FragmentShaderPath);
	ImGui::SameLine();

	if (ImGui::Button("Choose Fragment", m_ButtonSize))
	{
		std::vector<std::string> filter = {"Fragment Files", "*.frag"};
		Utils::FileDialog::OpenFile("Select Fragment Shader File", ".", m_FragmentShaderPath, filter, pfd::opt::none);
	}

	ImGui::Text("Comp");
	ImGui::SameLine();
	ImGui::InputText("##ComputeShaderFilePath", &m_ComputeShaderPath);
	ImGui::SameLine();

	if (ImGui::Button("Choose Fragment", m_ButtonSize))
	{
		std::vector<std::string> filter = { "Compute Files", "*.comp" };
		Utils::FileDialog::OpenFile("Select Compute Shader File", ".", m_ComputeShaderPath, filter, pfd::opt::none);
	}

	ImGui::Text("Wireframe Mode");
	ImGui::SameLine();
	ImGui::Checkbox("##Wireframe", &Framework::Scene::GetWireframeMode());

	if (ImGui::Button("Render", m_ButtonSize))
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