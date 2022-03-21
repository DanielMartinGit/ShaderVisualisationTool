#pragma once

#include "../../../Vendor/GLAD/glad.h"

#include <fstream>
#include <sstream>
#include <iostream>

namespace Framework
{
	class Shader
	{
		public:
			Shader()
			{
				m_ShaderCode = "";
				m_Shader = 0;
				m_ShaderType = GL_VERTEX_SHADER;
			}

			Shader(const char* path, GLuint shaderType)
			{
				m_ShaderCode = "";
				m_Shader = 0;

				LoadShaderFile(path);
				SetShaderType(shaderType);
			}
			~Shader() {}

		public:
			void LoadShaderFile(const char* path)
			{
				std::cout << "Loading shader from: " << path << std::endl;

				try
				{
					std::stringstream shaderStream;

					std::ifstream shaderFile(path);
					shaderStream << shaderFile.rdbuf();

					std::string shaderString = shaderStream.str();
					SetShaderCode(shaderString.c_str());

					shaderFile.close();
					std::cout << "Loaded Shader File at:" << path << std::endl;
				}
				catch (std::ofstream::failure e)
				{
					std::cout << "Couldn't read shader file!" << std::endl;
				}
		}

			const char* GetShaderCode() { return m_ShaderCode; }
			GLuint& GetShaderType() { return m_ShaderType; }
			uint32_t& GetShader() { return m_Shader; }
			bool& GetIsCompiled() { return m_IsCompiled; }

			void SetShaderCode(const char* shaderCode) { m_ShaderCode = shaderCode; }
			void SetShaderType(GLuint shaderType) { m_ShaderType = shaderType; }
			void SetShader(uint32_t shader) { m_Shader = shader; }
			void SetIsCompiled(bool compiled) { m_IsCompiled = compiled; }

		public:
			bool m_IsCompiled;
			const char* m_ShaderCode;

			uint32_t m_Shader;
			GLuint m_ShaderType;
	};
}