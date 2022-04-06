#pragma once
#include "../../../../../Framework/src/Panels/BasePanel/BasePanel.h"
#include "../../../../../Framework/src/Utils/FileSystem.h"
#include "../../../../../Framework/src/Utils/FileDialog.h"

namespace Menus
{
	class ShaderCreator : public Framework::Panel
	{
		public:
			ShaderCreator();
			~ShaderCreator(); 

		public:
			void OnImGuiRender();

		public:
			std::string& GetShaderFilePath() { return m_FileDestination; }

		private:
			std::string m_FileName;
			std::string m_FileDestination;
	};
}