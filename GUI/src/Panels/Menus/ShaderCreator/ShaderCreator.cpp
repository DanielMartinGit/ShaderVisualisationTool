#include "ShaderCreator.h"

Menus::ShaderCreator::ShaderCreator()
{
	m_FileDestination = "";
	m_FileName = "";

	ShowPanel(false);
}
Menus::ShaderCreator::~ShaderCreator() {}

void Menus::ShaderCreator::OnImGuiRender()
{
	ImGui::Begin("Create Shader", &GetActiveState(), ImGuiWindowFlags_NoResize);
	ImGui::SetWindowSize(ImVec2(550, 200));

	ImGui::Text("Shader Name");
	ImGui::SameLine();
	ImGui::InputText("##Name", &m_FileName);

	ImGui::Text("Shader Path");
	ImGui::SameLine();
	ImGui::InputText("##Destination", &m_FileDestination);
	ImGui::SameLine();
	if (ImGui::Button("Destination"))
	{
		m_FileDestination = Utils::FileDialog::SelectFolder("Select Shader File Destination");
	}

	if (ImGui::Button("Create"))
	{
		Utils::FileSystem::CreateShaderFile(m_FileDestination.c_str(), m_FileName.c_str(), ".frag");
		ShowPanel(false);
	}

	ImGui::End();
}