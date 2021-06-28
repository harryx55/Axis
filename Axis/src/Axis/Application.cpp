#include "pch.h"
#include <Axis/Application.h>
#include <glad/glad.h>


namespace Axis {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		AX_ASSERT(!s_Instance, "multiple instances of application not allowed");
		s_Instance = this;

		MainWindow = new WindowsWindow(props);
	}

	Application::~Application()
	{
		delete MainWindow;
	}

	void Application::Run()
	{
		while (!glfwWindowShouldClose(MainWindow->GetWindow()))
		{
			MainWindow->onUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.Push(layer);
		layer->OnAttach();	
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
}