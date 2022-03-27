#include "ScriptEditor.h"

Panels::ScriptEditor::ScriptEditor()
{
	m_ScriptLanguage = TextEditor::LanguageDefinition::Lua();
}
Panels::ScriptEditor::~ScriptEditor() {}

void Panels::ScriptEditor::OnImGuiRender()
{
	ImGui::Begin("Script Editor", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_MenuBar);
	
	OnMenubarRender();
	OnTextEditorRender();

	ImGui::End();
}

void Panels::ScriptEditor::OnMenubarRender()
{
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Open Shader File"))
			{
				std::vector<std::string> filters = { "Shader File", "*.vert", "*.frag", "*.comp" };
				Utils::FileDialog::OpenFile("Open Shader File", ".", m_ShaderPath, filters, pfd::opt::none);

				m_ShaderCode = Utils::FileSystem::LoadShaderFile(m_ShaderPath.c_str());
				Panels::Console::PrintToConsole(Panels::MessageType::MESSAGE, m_ShaderCode.c_str());
				m_TextEditor.InsertText(m_ShaderCode);
			}

			if (ImGui::MenuItem("Save Shader"))
			{
				m_ShaderCode = m_TextEditor.GetText();
				Utils::FileSystem::SaveShaderFile(m_ShaderPath.c_str(), m_ShaderCode.c_str());
				Panels::Console::PrintToConsole(Panels::MessageType::MESSAGE, "Shader File Saved");
			}

			ImGui::EndMenu();
		}

		if (ImGui::Button("Save and Compile", ImVec2(130, 20)))
		{

		}

		ImGui::EndMenuBar();
	}
}

void Panels::ScriptEditor::OnTextEditorRender()
{
	m_TextEditor.Render("###Code", ImVec2(ImGui::GetWindowSize()));
}