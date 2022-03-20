#include "PanelManager.h"

Framework::PanelManager::PanelManager() {}
Framework::PanelManager::~PanelManager() {}

void Framework::PanelManager::AddPanel(const char* name, Framework::Panel* panel)
{
	m_Panels[name] = panel;
}

void Framework::PanelManager::LoadPanelResources() {}

void Framework::PanelManager::RenderActivePanels()
{
	for (auto panel : m_Panels)
	{
		if (panel.second->GetActiveState())
		{
			panel.second->OnImGuiRender();
		}
	}
}