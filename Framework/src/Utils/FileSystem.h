#pragma once
#include <fstream>
#include <sstream>
#include <iostream>

namespace Utils
{
	class FileSystem
	{
		public:
			FileSystem() {}
			~FileSystem() {}

		public:
			static std::string LoadShaderFile(const char* path)
			{
				try
				{
					std::stringstream shaderStream;
					std::ifstream shaderFile(path);
					shaderStream << shaderFile.rdbuf();

					m_ShaderString = shaderStream.str();

					shaderFile.close();
				}
				catch (std::ofstream::failure e)
				{
					std::cout << "Couldn't read shader file!" << std::endl;
				}

				return m_ShaderString;
			}

			static void SaveShaderFile(const char* path, const char* source)
			{
				std::ofstream output(path);
				output << static_cast<std::string>(source);
				output.close();
			}

		private:
			inline static std::string m_ShaderString;
			inline static std::string m_ShaderPath;
	};
}