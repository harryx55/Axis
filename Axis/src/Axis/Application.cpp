#include "pch.h"
#include <Axis/Application.h>
#include <glad/glad.h>

#include "Renderer/OpenGL/OpenGLErrors.h"

namespace Axis {

	Application* Application::s_Instance = nullptr;

	const char* vertexSrc = R"(
			#version 140
			in vec3 aPos;
			in vec3 aColor;
			
			out vec3 color;
			void main()
			{
				gl_Position = vec4(aPos, 1.0);
				color = aColor;
			})";

	const char* fragmentSrc = R"(
			#version 140
			out vec4 fragColor;
			in vec3 color;

			void main()
			{
				fragColor = vec4(0.6, 0.5, 0.4, 1.0) * vec4(color, 1.0);
			})";

	Application::Application()
	{
		s_Instance = this;
		AX_CORE_ASSERT(!s_Instance, "multiple instances of application not allowed");
		MainWindow = new WindowsWindow(props);
		
		vertexArray = std::make_unique<OpenGLVertexArray>();
		vertexArray->Bind();
		float vertices[] =
		{
			-0.5f, -0.5f,	1.0f, 0.0f, 0.0f,
			-0.5f,  0.5f,	0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,	0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f,	0.0f, 1.0f, 0.0f
		};

		VertexBuffer = std::make_unique<OpenGLVertexBuffer>(vertices, sizeof(float) * 20);
		uint16_t indices[] =
		{
			0, 1, 2, 2, 3, 0
		};

		IndexBuffer = std::make_unique<OpenGLIndexBuffer>(indices, sizeof(uint16_t) * 6);
		layout.AttachElement(0, 2, 5);
		layout.AttachElement(1, 3, 5);

		shader = std::make_unique<OpenGLShaders>(vertexSrc, fragmentSrc);
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

			shader->bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);

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