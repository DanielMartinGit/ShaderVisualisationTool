#pragma once

#include "../../../Framework/src/Initialisation/Initialisation.h"
#include "../../../Framework/src/Panels/PanelManager/PanelManager.h"
#include "../../../Framework/src/Window/Window.h"
#include "../../../Framework/src/Scene/Scene.h"

namespace ShaderTool
{
	class Application : Framework::Window
	{
		public:
			Application();
			~Application();

		public:
			void InitApp();
			void MainApplicationLoop();

			void ProcessInput() override;
			void Update(float deltaTime) override;
			void Render() override;

		private:
			Framework::Scene m_Scene;
			Framework::PanelManager m_PanelManager;

		private:
			Panels::Console m_Console;
			Panels::Viewport m_Viewport;
			Panels::Resources m_Resources;
			Panels::SceneProperties m_SceneProperties;
			Panels::ScriptEditor m_ScriptEditor;
	};
}