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
		gladLoadGL();
	}

	Application::~Application()
	{
		delete MainWindow;
	}

	void Application::Run()
	{
		while (!glfwWindowShouldClose(MainWindow->GetWindow()))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.4f, 0.5f, 0.6f, 1.0f);

			for (ILayer* layer : m_LayerStack)
				layer->OnUpdate();

			m_imguiLayer->Begin();
			for (ILayer* layer : m_LayerStack)
				layer->OnImguiRender();
			m_imguiLayer->End();

			MainWindow->onUpdate();
		}
	}

	void Application::PushLayer(ILayer* layer)
	{
		m_LayerStack.Push(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(ILayer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
}