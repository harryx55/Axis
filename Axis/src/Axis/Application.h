#pragma once

#include "Core.h"
#include "platform/windows/WindowsWindow.h"


namespace Axis
{
	class AXIS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		WindowProps props { "Axis Engine", 1280, 720 };

		WindowsWindow* m_Window;
		bool running = true;
	};

	Application* CreateApplication();
}