#include "ScriptEditor.h"

Panels::ScriptEditor::ScriptEditor()
{
	m_ShaderCreator = Menus::ShaderCreator();
	m_ShowShaderCreationMenu = false;
}
Panels::ScriptEditor::~ScriptEditor() {}

void Panels::ScriptEditor::OnImGuiRender()
{
	ImGui::Begin("Script Editor", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_MenuBar);
	
	OnMenubarRender();
	OnTextEditorRender();

	if (m_ShaderCreator.GetActiveState())
		m_ShaderCreator.OnImGuiRender();

	ImGui::End();
}

void Panels::ScriptEditor::OnMenubarRender()
{
	ImGui::Text(m_OpenedFileTitle.c_str());

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Create Shader"))
				m_ShaderCreator.ShowPanel(true);

			if (ImGui::MenuItem("Open Shader"))
			{
				std::vector<std::string> filters = { "Shader File", "*.vert *.frag *.comp"};
				Utils::FileDialog::OpenFile("Open Shader File", ".", m_ShaderPath, filters, pfd::opt::none);

				m_ShaderCode = Utils::FileSystem::LoadShaderFile(m_ShaderPath.c_str());
				Panels::Console::PrintToConsole(Panels::MessageType::MESSAGE, m_ShaderCode.c_str());
				m_TextEditor.InsertText(m_ShaderCode);
				m_OpenedFileTitle = std::filesystem::path(m_ShaderPath).filename().string();
			}

			if (ImGui::MenuItem("Save Shader"))
			{
				m_ShaderCode = m_TextEditor.GetText();
				Utils::FileSystem::SaveShaderFile(m_ShaderPath.c_str(), m_ShaderCode.c_str());
				Panels::Console::PrintToConsole(Panels::MessageType::MESSAGE, "Shader File Saved");
			}

			ImGui::EndMenu();
		}

		if (ImGui::Button("Save and Compile", ImVec2(130, 20))) {}

		ImGui::EndMenuBar();
	}
}

void Panels::ScriptEditor::OnTextEditorRender()
{
	m_TextEditor.Render("###Code", ImVec2(ImGui::GetWindowSize()));
}