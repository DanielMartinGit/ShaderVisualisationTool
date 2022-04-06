#pragma once

#include "../../../Vendor/ImGui/imgui.h"
#include "../../../Vendor/ImGui/imgui_stdlib.h"

namespace Framework
{
	class Panel
	{
		public:
			Panel() { m_IsActive = true; m_IsHovered = false; }
			~Panel() {}

		public:
			virtual void OnImGuiRender() {}

		public:
			void ShowPanel(bool show) { m_IsActive = show; }
			void SetIsHovered(bool hovered) { m_IsHovered = hovered; }
			void HidePanel() { m_IsActive = false; }

		public:
			bool& GetActiveState() { return m_IsActive; }
			bool& GetHoveredState() { return m_IsHovered; }

		private:
			bool m_IsHovered;
			bool m_IsActive;
	};
}