#include "pch.h"
#include "WindowsWindow.h"
#include "Log.h"

#include "glad/glad.h"

namespace Axis
{
	static bool sGLFW_INIT = false;

	WindowsWindow::WindowsWindow(const WindowProps& props)
		: m_window(NULL)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_data.title = props.title;
		m_data.width = props.width;
		m_data.height = props.height;

		
		if (!sGLFW_INIT)
		{
			int status = glfwInit();
			AX_CORE_ASSERT(status, "[ERROR]: GLFW not Initialized");

			sGLFW_INIT = true;
		}

		// Create opengl 3.1 context
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		AX_CORE_INFO("Creating Window {0} ({1}, {2})", m_data.title, m_data.width, m_data.height);

		m_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		SetVSync(true);

		AX_CORE_INFO("Created Window {0} ({1}, {2})", "OpenGL Context: ", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);

		m_data.VSync = enabled;
	}
}

