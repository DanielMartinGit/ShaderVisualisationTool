#pragma once
#include "../Menus/ShaderCreator/ShaderCreator.h"
#include "../../../../Framework/src/Scene/Scene.h"
#include "../../../../Framework/Vendor/TextEditor/TextEditor.h"

namespace Panels
{
	class ScriptEditor : public Framework::Panel
	{
		public:
			ScriptEditor();
			~ScriptEditor();

		public:
			void OnMenubarRender();
			void OnTextEditorRender();
			void OnImGuiRender() override;

		private:
			TextEditor m_TextEditor;
			Menus::ShaderCreator m_ShaderCreator;

		private:
			std::string m_OpenedFileTitle;
			std::string m_ShaderCode;
			std::string m_ShaderPath;
			bool m_ShowShaderCreationMenu;
	};
}