#include "ShaderProgram.h"

Framework::ShaderProgram::ShaderProgram()
{
	m_ShaderProgramID = 0;
}
Framework::ShaderProgram::~ShaderProgram() {}

void Framework::ShaderProgram::CreateShader(Framework::Shader& shader)
{
	shader.InitialiseShader(glCreateShader(shader.GetShaderType()));

	glShaderSource(shader.GetShader(), 1, &shader.m_ShaderCode, NULL);
	glCompileShader(shader.GetShader());

	Panels::Console::PrintToConsole(Panels::MessageType::MESSAGE, shader.m_ShaderCode);	

	if (CheckShaderCompilation(shader.GetShader()))
	{
		shader.SetIsCompiled(true);
		m_Shaders.push_back(shader);
		Panels::Console::PrintToConsole(Panels::MessageType::MESSAGE, "Shader loaded");
	}
}

void Framework::ShaderProgram::Link()
{
	m_ShaderProgramID = glCreateProgram();

	for (auto shader : m_Shaders)
	{
		if(shader.GetIsCompiled())
			glAttachShader(m_ShaderProgramID, shader.GetShader());
	}
	
	glLinkProgram(m_ShaderProgramID);
	
	if (CheckShaderLink(m_ShaderProgramID))
	{
		for (auto shader : m_Shaders)
		{
			glDeleteShader(shader.GetShader());
		}

		Panels::Console::PrintToConsole(Panels::MessageType::MESSAGE, "Shaders linked");
	}
}

void Framework::ShaderProgram::Use()
{
	glUseProgram(m_ShaderProgramID);
}

bool Framework::ShaderProgram::CheckShaderCompilation(GLuint shader)
{
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::string errorMessage;
		errorMessage.append(infoLog);

		Panels::Console::PrintToConsole(Panels::MessageType::ISSUE, errorMessage.c_str());
		std::cout << infoLog << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool Framework::ShaderProgram::CheckShaderLink(GLuint shaderProgram)
{
	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::string errorMessage;
		errorMessage.append(infoLog);

		Panels::Console::PrintToConsole(Panels::MessageType::ISSUE, errorMessage.c_str());		return false;
	}
	else
	{
		return true;
	}
}

void Framework::ShaderProgram::ClearProgram()
{
	m_ShaderProgramID = 0;
	m_Shaders.clear();
}