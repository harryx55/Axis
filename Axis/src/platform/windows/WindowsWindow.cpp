
#include "pch.h"
#include "WindowsWindow.h"

#include "Log.h"


namespace Axis
{
	static bool sGLFW_INIT = false;

	WindowsWindow::WindowsWindow(const WindowProps& props)
		: m_window(NULL)
	{
		Init(props);
	}

	WindowsWindow* WindowsWindow::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::~WindowsWindow()
	{
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_data.title = props.title;
		m_data.width = props.width;
		m_data.height = props.height;

		AX_CORE_INFO("Creating Window {0} ({1}, {2})", m_data.title, m_data.width, m_data.height);
		
		if (!sGLFW_INIT)
		{
			int status = glfwInit();
			// Assert: AX_CORE_ERROR(status, "[ERROR]: GLFW not Initialized");

			sGLFW_INIT = true;
		}

		m_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		SetVSync(true);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		// TODO: fix glfwSwapBuffers(m_window) error
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

