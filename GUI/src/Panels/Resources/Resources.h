#pragma once
#include "../../../../Framework/src/Panels/BasePanel/BasePanel.h"
#include "../../../../Framework/src/Scene/Scene.h"
#include "../../../../Framework/Vendor/ImGui/imgui.h"

namespace Panels
{
	class Resources : public Framework::Panel
	{
		public:
			Resources();
			~Resources();

		public:
			void OnImGuiRender() override;

		public:
			void SetLoadedShaderCount(int count) { m_ShaderCount = count; }

		private:
			int m_ShaderCount;
	};
}