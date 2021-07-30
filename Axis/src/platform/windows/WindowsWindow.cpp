#include "pch.h"
#include "WindowsWindow.h"
#include "Log.h"

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

		int status = glfwInit();
		AX_CORE_ASSERT(!status, "[ERROR]: GLFW not Initialized");

		m_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), NULL, NULL);
		m_Context = new OpenGLContext(m_window);
		m_Context->Init();
		
		glfwSetWindowUserPointer(m_window, &m_data);
		SetVSync(true);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);

		m_data.VSync = enabled;
	}
}

