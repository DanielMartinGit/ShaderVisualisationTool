#include "Viewport.h"

Panels::Viewport::Viewport() {}
Panels::Viewport::~Viewport() {}

void Panels::Viewport::OnImGuiRender()
{
	ImGui::Begin("Viewport", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
	
	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();
	ImGui::Image((ImTextureID)Framework::Scene::GetRenderedScene(), vWindowSize);

	ImGui::End();
}