#pragma once

#include "Core.h"
#include "LayerStack.h"
#include "platform/windows/glfwMain.h"
#include "Axis/Imgui/ImguiLayer.h"

#include "Platform/windows/WindowsInput.h"
#include "Renderer/Cameras.h"

namespace Axis
{
	class AXIS_API Application
	{
	public:
		Application();
		virtual ~Application();

	public:
		static Application& Get() { return *s_Instance; }
		glfwWindow& GetWindow() { return *MainWindow; }
		void Run();

		void PushLayer(ILayer* layer);
		void PushOverlay(ILayer* layer);

	private:
		static Application* s_Instance;
		glfwWindow* MainWindow;

		ImguiLayer *m_imguiLayer;
		LayerStack m_LayerStack;
		bool running = true;
	};

	Application* CreateApplication();
}