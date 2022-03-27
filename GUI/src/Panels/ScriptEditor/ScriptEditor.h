#pragma once
#include "../../../../Framework/src/Panels/BasePanel/BasePanel.h"
#include "../../../../Framework/src/Scene/Scene.h"
#include "../../../../Framework/src/Utils/FileDialog.h"
#include "../../../../Framework/src/Utils/FileSystem.h"

#include "../../../../Framework/Vendor/ImGui/imgui_stdlib.h"
#include "../../../../Framework/Vendor/ImGui/imgui.h"
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
			TextEditor::LanguageDefinition m_ScriptLanguage;
			TextEditor m_TextEditor;
			std::string m_ShaderCode;
			std::string m_ShaderPath;
	};
}