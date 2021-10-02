#pragma once

#include "Core.h"
#include "LayerStack.h"
#include "platform/windows/WindowsWindow.h"
#include "Axis/Imgui/ImguiLayer.h"

#include "Platform/windows/WindowsInput.h"
#include "Renderer/Cameras.h"

#include "Axis/Core/Timestep.h"

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

		void PushLayer(ILayer* layer);
		void PushOverlay(ILayer* layer);

	private:
		WindowProps props { "Axis Engine", 1280, 720 };
		static Application* s_Instance;
		WindowsWindow* MainWindow;

		ImguiLayer *m_imguiLayer;
		LayerStack m_LayerStack;
		bool running = true;

	private:
		Axis::Timestep timestep;
		float LastFrame = 0.0f;
	};

	Application* CreateApplication();
}