#include "pch.h"
#include <Axis/Application.h>
#include <glad/glad.h>

#include "Renderer/Renderer.h"
#include "Renderer/RenderCommand.h"

namespace Axis {

	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		s_Instance = this;
		AX_CORE_ASSERT(s_Instance, "multiple instances of application not allowed");
		MainWindow = new glfwWindow(1280, 720, "Axis Engine");

		m_imguiLayer = new ImguiLayer();
		m_imguiLayer->OnAttach();
	}

	Application::~Application()
	{
		delete MainWindow;
	}

	void Application::Run()
	{
		while (!glfwWindowShouldClose(MainWindow->GetWindow()))
		{
			MainWindow->calculateDeltaTime();
			AX_CORE_INFO("{0}{1}", MainWindow->GetFPS(), " FPS");

			for (ILayer* layer : m_LayerStack)
			{
				layer->OnUpdate(timestep);
			}

			m_imguiLayer->Begin();
			for (ILayer* layer : m_LayerStack)
			{
				m_imguiLayer->OnAttach();
				m_imguiLayer->OnImguiRender();
				layer->OnImguiRender();
			}

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
