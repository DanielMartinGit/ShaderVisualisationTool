#include "SceneProperties.h"

Panels::SceneProperties::SceneProperties()
{
	m_VertexShaderPath = "";
	m_FragmentShaderPath = "";
	m_ComputeShaderPath = "";

	m_VertexUniformCount = 0;
	m_FragmentUniformCount = 0;
}
Panels::SceneProperties::~SceneProperties() {}

void Panels::SceneProperties::OnImGuiRender()
{
	ImGui::Begin("Scene Properties", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	ImGui::Text("Vert");
	ImGui::SameLine();
	ImGui::InputText("##VertexShaderFilePath", &m_VertexShaderPath);
	ImGui::SameLine();
	
	if (ImGui::Button("Load Vert", m_ButtonSize))
	{
		std::vector<std::string> filter = { "Vertex Files", "*.vert" };
		Utils::FileDialog::OpenFile("Select Vertex Shader File", ".", m_VertexShaderPath, filter, pfd::opt::none);
	}

	ImGui::Text("Frag");
	ImGui::SameLine();
	ImGui::InputText("##FragmentShaderFilePath", &m_FragmentShaderPath);
	ImGui::SameLine();

	if (ImGui::Button("Load Frag", m_ButtonSize))
	{
		std::vector<std::string> filter = {"Fragment Files", "*.frag"};
		Utils::FileDialog::OpenFile("Select Fragment Shader File", ".", m_FragmentShaderPath, filter, pfd::opt::none);
	}

	ImGui::Text("Comp");
	ImGui::SameLine();
	ImGui::InputText("##ComputeShaderFilePath", &m_ComputeShaderPath);
	ImGui::SameLine();

	if (ImGui::Button("Load Comp", m_ButtonSize))
	{
		std::vector<std::string> filter = { "Compute Files", "*.comp" };
		Utils::FileDialog::OpenFile("Select Compute Shader File", ".", m_ComputeShaderPath, filter, pfd::opt::none);
	}

	ImGui::Text("Wireframe Mode");
	ImGui::SameLine();
	ImGui::Checkbox("##Wireframe", &Framework::Scene::GetWireframeMode());

	ImGui::Text("Primitive Type");
	ImGui::SameLine();

	if (ImGui::BeginCombo("##Primitives", ""))
	{
		if (ImGui::Selectable("Triangle"))
		{

		}
		if (ImGui::Selectable("Quad"))
		{

		}

		ImGui::EndCombo();
	}

	OnImGuiRenderVertexUniforms();
	OnImGuiRenderFragmentUniforms();


	if (ImGui::Button("Render", ImVec2(50, 20)))
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

void Panels::SceneProperties::OnImGuiRenderVertexUniforms()
{
	if (m_VertexUniformCount != 0)
	{
		ImGui::Text("Vertex Shader Uniform");

		for (int uniformCount = 0; uniformCount < m_VertexUniformCount; ++uniformCount)
		{
			std::string uniformName;
			std::string uniformVariable;

			ImGui::Text("Uniform Name");
			ImGui::SameLine();
			ImGui::InputText("##UniformName", &uniformName);
			ImGui::Text("Uniform Value");
			ImGui::SameLine();
			ImGui::InputText("##UniformVar", &uniformVariable);
			ImGui::Separator();
		}
	}

	if (ImGui::Button("+", m_ButtonSize))
		++m_VertexUniformCount;

	ImGui::SameLine();

	if (ImGui::Button("-", m_ButtonSize))
		if(m_VertexUniformCount != 0)
			--m_VertexUniformCount;
}

void Panels::SceneProperties::OnImGuiRenderFragmentUniforms()
{

}