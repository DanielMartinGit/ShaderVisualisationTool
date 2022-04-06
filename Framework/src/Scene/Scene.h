#pragma once
#include "../Graphics/ShaderProgram/ShaderProgram.h"
#include "../Graphics/FramebufferObject/Framebuffer.h"
#include "../Primitives/Primitives.h"

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
			static Framework::ShaderProgram& GetShaderProgram() { return m_ShaderProgram; }

		public:
			static bool& GetWireframeMode() { return m_WireframeMode; }
			static uint32_t GetRenderedScene() { return m_FBO.GetFramebufferObject(); }

		private:
			static inline Framework::Framebuffer m_FBO;
			static inline Framework::ShaderProgram m_ShaderProgram;
			static inline bool m_WireframeMode;

		private:
			Primitives::Triangle m_Triangle;
			Primitives::Quad m_Quad;
	};
}