#pragma once
#include "../../../../Framework/src/Panels/BasePanel/BasePanel.h"
#include <string>

namespace Panels
{
	enum class MessageType { MESSAGE, WARNING, ISSUE, ACTION };

	class Console : public Framework::Panel
	{
		public:
			Console();
			~Console();

		public:
			void OnImGuiRender() override;
			void ClearConsole();

		public:
			static void PrintToConsole(MessageType messageType, const char* message, ...);

		private:
			MessageType m_MessageType;
			ImGuiTextFilter m_Filter;

		private:
			inline static ImGuiTextBuffer m_Buffer;
			inline static ImVector<int> m_LineOffsets;

		private:
			inline static int m_ActionCount;
			inline static int m_WarningCount;
			inline static int m_ErrorCount;
			inline static int m_MessageCount;

		private:
			bool m_AutoScroll;

			bool m_ShowActions;
			bool m_ShowWarnings;
			bool m_ShowErrors;
			bool m_ShowMessages;
	};
}