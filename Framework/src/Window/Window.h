#pragma once
#include "../../src/Initialisation/Initialisation.h"

namespace Framework
{
	class Window
	{
		public:
			Window();
			~Window();

		public:
			void InitWindow(uint32_t width, uint32_t height, const char* title);
			void BeginFrame();
			void EndFrame();

			void DestroyWindow();

		public:
			virtual void ProcessInput();
			virtual void Update(float deltaTime);
			virtual void Render();

		public:
			GLFWwindow& GetCurrentWindow() { return *m_Window; }

		protected:
			const char* m_GLSLVersion = "#version 460";
			GLFWwindow* m_Window;
	};
}