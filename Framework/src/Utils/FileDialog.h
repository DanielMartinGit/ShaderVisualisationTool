#pragma once
#include "../../Vendor/PFD/portable-file-dialogs.h"
#include "../../../GUI/src/Panels/Console/Console.h"

namespace Utils
{
	class FileDialog
	{
		public:
			FileDialog() {}
			~FileDialog() {}

		public:
			// Options are multiselect (for multiple files), None, Force Overwrite
			static void OpenFile(std::string windowTitle, std::string initialPath, std::string& output, std::vector<std::string> filters = { "All Files", "*" }, pfd::opt option = pfd::opt::none)

 			{
				auto selected = pfd::open_file(windowTitle, initialPath, filters, option).result();

				for (auto const& filename : selected)
				{
					std::string message = "File Opened: ";
					message.append(filename);

					output = selected[0];

					Panels::Console::PrintToConsole(Panels::MessageType::ACTION, message.c_str());
				}
			}
	};
}