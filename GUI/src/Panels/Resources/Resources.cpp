#include "Resources.h"

Panels::Resources::Resources()
{
	m_ShaderCount = 0;
}
Panels::Resources::~Resources() {}

void Panels::Resources::OnImGuiRender()
{
	ImGui::Begin("Resources", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
	
	ImGui::Text("Shaders Loaded: %i", m_ShaderCount);
	
	ImGui::End();
}