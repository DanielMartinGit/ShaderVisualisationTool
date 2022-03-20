#pragma once
#include "../Graphics/ShaderProgram/ShaderProgram.h"
#include "../Graphics/FramebufferObject/Framebuffer.h"

namespace Framework
{
	class Scene
	{
		public:
			Scene();
			~Scene();

		public:
			void InitScene();

			void ProcessInput();
			void Update(double deltaTime);
			void Render();

			static uint32_t GetRenderedScene() { return m_FBO.GetFramebufferObject(); }

		private:
			static inline Framework::Framebuffer m_FBO;
			Framework::ShaderProgram m_ShaderProgram;
	};
}