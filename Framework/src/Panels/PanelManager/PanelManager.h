#pragma once

#include "../BasePanel/BasePanel.h"

#include "../../../../GUI/src/Panels/Viewport/Viewport.h"
#include "../../../../GUI/src/Panels/Resources/Resources.h"
#include "../../../../GUI/src/Panels/Console/Console.h"
#include "../../../../GUI/src/Panels/SceneProperties/SceneProperties.h"

#include <unordered_map>

namespace Framework
{
	class PanelManager
	{
		public:
			PanelManager();
			~PanelManager();

		public:
			void RenderActivePanels();
			void LoadPanelResources();

		public:
			void AddPanel(const char* name, Framework::Panel* panel);

		public:
			static Framework::Panel* GetPanel(const char* name)
			{
				auto pairFound = m_Panels.find(name);

				if (pairFound != m_Panels.end())
					return pairFound->second;
				else
					return nullptr;
			}

		private:
			inline static std::unordered_map<std::string, Framework::Panel*> m_Panels;
	};
}