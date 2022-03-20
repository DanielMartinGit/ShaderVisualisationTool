#pragma once
#include "../../../../Framework/src/Panels/BasePanel/BasePanel.h"
#include "../../../../Framework/src/Scene/Scene.h"
#include "../../../../Framework/Vendor/ImGui/imgui.h"

namespace Panels
{
	class Viewport : public Framework::Panel
	{
		public:
			Viewport();
			~Viewport();

		public:
			void OnImGuiRender() override;
	};
}