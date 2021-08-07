#include "pch.h"
#include "WindowsWindow.h"

#include "glad/glad.h"

namespace Axis
{
	WindowsWindow::WindowsWindow(const WindowProps& props)
		: m_window(NULL)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwTerminate();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_data.title = props.title;
		m_data.width = props.width;
		m_data.height = props.height;

		int glfwStatus = glfwInit();
		AX_CORE_ASSERT(!glfwStatus, "[ERROR]: GLFW not Initialized");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

		m_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), NULL, NULL);
		AX_CORE_ASSERT(!m_window, "[ERROR]: window not created");

		glfwMakeContextCurrent(m_window);
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* w, int width, int height)
			{
				glViewport(0, 0, width, height);
			});

		int gladStatus = gladLoadGL();
		AX_CORE_ASSERT(!gladStatus, "[ERROR]: GLAD not Initialized");

		glfwSetWindowUserPointer(m_window, &m_data);
		SetVSync(true);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);

		m_data.VSync = enabled;
	}
}

