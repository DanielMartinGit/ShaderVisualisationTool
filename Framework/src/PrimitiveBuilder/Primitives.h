#pragma once
#include "../../Vendor/GLAD/glad.h"
#include "../Graphics/ShaderProgram/ShaderProgram.h"

namespace Primitives
{
	class Square
	{
		public:
			Square() {}
			~Square() {}

		public:
			void RenderSquare()
			{

			}
	};

	class Triangle
	{
		public:
			Triangle() 
			{
				m_VAO = 0;
				m_VBO = 0;
			}
			~Triangle() {}

		public:
			void InitTriangle()
			{
				glGenVertexArrays(1, &m_VAO);
				glGenBuffers(1, &m_VBO);

				glBindVertexArray(m_VAO);
				glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
				glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertices), m_Vertices, GL_STATIC_DRAW);

				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
				glEnableVertexAttribArray(0);

				glBindBuffer(GL_ARRAY_BUFFER, 0);
				glBindVertexArray(0);
			}

			void RenderTriangle(Framework::ShaderProgram& shaderProgram)
			{
				shaderProgram.Use();
				glBindVertexArray(m_VAO);
				glDrawArrays(GL_TRIANGLES, 0, 3);
			}

		private:
			unsigned int m_VAO;
			unsigned int m_VBO;

			float m_Vertices[9] =
			{
				-0.5f, -0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				0.0f,  0.5f, 0.0f
			};
	};
}