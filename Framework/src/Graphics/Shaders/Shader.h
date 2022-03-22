#pragma once

#include "../../../Vendor/GLAD/glad.h"
#include "../../../GUI/src/Panels/Console/Console.h"

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
				m_ShaderString = "";
				m_ShaderCode = "";
				m_Shader = 0;
				m_ShaderType = GL_VERTEX_SHADER;
			}

			Shader(const char* path, GLuint shaderType)
			{
				m_ShaderString = "";
				m_Shader = 0;

				SetShaderType(shaderType);
				LoadShaderFile(path);
			}
			~Shader() {}

		public:
			void LoadShaderFile(const char* path)
			{
				try
				{
					std::stringstream shaderStream;
					std::ifstream shaderFile(path);
					shaderStream << shaderFile.rdbuf();

					m_ShaderString = shaderStream.str();
					SetShaderCode(m_ShaderString.c_str());
					shaderFile.close();

					Panels::Console::PrintToConsole(Panels::MessageType::MESSAGE, "Loaded shader file");
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

			void InitialiseShader(uint32_t shader) { m_Shader = shader; }
			void SetShaderCode(const char* shaderCode) { m_ShaderCode = shaderCode; }
			void SetShaderType(GLuint shaderType) { m_ShaderType = shaderType; }
			void SetIsCompiled(bool compiled) { m_IsCompiled = compiled; }

		public:
			bool m_IsCompiled;
			const char* m_ShaderCode;

			std::string m_ShaderString;
			uint32_t m_Shader;
			GLuint m_ShaderType;
	};
}