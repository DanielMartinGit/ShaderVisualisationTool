#pragma once
#include "../Graphics/ShaderProgram/ShaderProgram.h"
#include "../Graphics/FramebufferObject/Framebuffer.h"
#include "../PrimitiveBuilder/Primitives.h"

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

		public:
			Framework::ShaderProgram& GetShaderProgram() { return m_ShaderProgram; }

		public:
			static uint32_t GetRenderedScene() { return m_FBO.GetFramebufferObject(); }

		private:
			static inline Framework::Framebuffer m_FBO;
			Framework::ShaderProgram m_ShaderProgram;

		private:
			Primitives::Triangle m_Triangle;
	};
}