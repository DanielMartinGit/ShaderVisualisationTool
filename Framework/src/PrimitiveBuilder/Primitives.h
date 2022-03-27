#pragma once
#include "../../Vendor/GLAD/glad.h"
#include "../Graphics/ShaderProgram/ShaderProgram.h"

namespace Primitives
{
	class Primitive
	{
		public:
			virtual void Init() {}
			virtual void Render(Framework::ShaderProgram& shaderProgram) {}
			virtual void Cleanup() {}

		protected:
			unsigned int m_VAO;
			unsigned int m_VBO;
			unsigned int m_EBO;
	};

	class Square : public Primitive
	{
		public:
			Square()
			{
				m_VAO = 0;
				m_VBO = 0; 
				m_EBO = 0;
			}
			~Square() {}

		public:
			void Init() override
			{
				glGenVertexArrays(1, &m_VAO);
				glGenBuffers(1, &m_VBO);
				glGenBuffers(1, &m_EBO);

				glBindVertexArray(m_VAO);

				glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
				glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertices), m_Vertices, GL_STATIC_DRAW);

				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_Indices), m_Indices, GL_STATIC_DRAW);

				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
				glEnableVertexAttribArray(0);

				glBindBuffer(GL_ARRAY_BUFFER, 0);
				glBindVertexArray(0);
			}

			void Render(Framework::ShaderProgram& shaderProgram) override
			{
				shaderProgram.Use();
				glBindVertexArray(m_VAO);
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			}

			void Cleanup() override
			{
				glDeleteVertexArrays(1, &m_VAO);
				glDeleteBuffers(1, &m_VBO);
				glDeleteBuffers(1, &m_EBO);
			}

		private:
			unsigned int m_Indices [6] = {  // note that we start from 0!
				0, 1, 3,   // first triangle
				1, 2, 3    // second triangle
			};

			float m_Vertices [18] = {
				0.5f,  0.5f, 0.0f,  // top right
				0.5f, -0.5f, 0.0f,  // bottom right
				-0.5f, -0.5f, 0.0f,  // bottom left
				-0.5f,  0.5f, 0.0f   // top left 
			};
	};

	class Triangle : public Primitive
	{
		public:
			Triangle() 
			{
				m_VAO = 0;
				m_VBO = 0;
			}
			~Triangle() {}

		public:
			void Init() override
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

			void Render(Framework::ShaderProgram& shaderProgram) override
			{
				shaderProgram.Use();
				glBindVertexArray(m_VAO);
				glDrawArrays(GL_TRIANGLES, 0, 3);
			}

			void Cleanup() override
			{
				glDeleteVertexArrays(1, &m_VAO);
				glDeleteBuffers(1, &m_VBO);
			}

		private:
			float m_Vertices [9] =
			{
				-0.5f, -0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				0.0f,  0.5f, 0.0f
			};
	};
}