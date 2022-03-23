#pragma once
#include "../../../../Framework/src/Panels/BasePanel/BasePanel.h"
#include "../../../../Framework/src/Scene/Scene.h"
#include "../../../../Framework/src/Utils/FileDialog.h"

#include "../../../../Framework/Vendor/ImGui/imgui_stdlib.h"
#include "../../../../Framework/Vendor/ImGui/imgui.h"

namespace Panels
{
	class SceneProperties : public Framework::Panel
	{
		public:
			SceneProperties();
			~SceneProperties();

		public:
			void OnImGuiRender() override;

		private:
			std::string m_VertexShaderPath;
			std::string m_FragmentShaderPath;

			ImVec2 m_ButtonSize { 50, 20 };
	};
}