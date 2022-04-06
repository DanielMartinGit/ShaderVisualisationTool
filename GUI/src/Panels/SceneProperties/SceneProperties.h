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
			void OnImGuiRenderVertexUniforms();
			void OnImGuiRenderFragmentUniforms();

		private:
			const char* m_PrimitiveTypes[2] = {"Triangle", "Quad"};
			std::string m_VertexShaderPath;
			std::string m_FragmentShaderPath;
			std::string m_ComputeShaderPath;

			ImVec2 m_ButtonSize { 35, 20 };

			size_t m_VertexUniformCount;
			size_t m_FragmentUniformCount;
	};
}