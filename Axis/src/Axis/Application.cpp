#include "pch.h"
#include <Axis/Application.h>
#include <glad/glad.h>


namespace Axis {

	Application* Application::s_Instance = nullptr;

	const char* vertexSrc = R"(
			#version 140
			in vec3 aPos;

			void main()
			{
				gl_Position = vec4(aPos, 1.0);
			})";

	const char* fragmentSrc = R"(
			#version 140
			out vec4 fragColor;

			void main()
			{
				fragColor = vec4(0.6, 0.5, 0.4, 1.0);
			})";

	Application::Application()
	{
		AX_ASSERT(!s_Instance, "multiple instances of application not allowed");
		s_Instance = this;

		MainWindow = new WindowsWindow(props);

		GLuint vao;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		float vertices[] =
		{
			-0.5f, -0.5f,
			 0.0f,  0.5f,
			 0.5f, -0.5f,
		};
		VertexBuffer = new OpenGLVertexBuffer(vertices, sizeof(float) * 6);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

		shader = new OpenGLShaders(vertexSrc, fragmentSrc);
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
			glDrawArrays(GL_TRIANGLES, 0, 3);

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