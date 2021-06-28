#pragma once

#include "Core.h"
#include "LayerStack.h"
#include "platform/windows/WindowsWindow.h"
#include <Axis/Imgui/ImguiLayer.h>


namespace Axis
{
	class AXIS_API Application
	{
	public:
		Application();
		virtual ~Application();

	public:
		static Application& Get() { return *s_Instance; }
		WindowsWindow& GetWindow() { return *MainWindow; }
		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		WindowProps props { "Axis Engine", 1280, 720 };
		static Application* s_Instance;
		WindowsWindow* MainWindow;

		LayerStack m_LayerStack;
		bool running = true;
	};

	Application* CreateApplication();
}