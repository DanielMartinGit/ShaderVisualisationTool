#pragma once

#include "../../../Framework/src/Initialisation/Initialisation.h"
#include "../../../Framework/src/Window/Window.h"

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
	};
}