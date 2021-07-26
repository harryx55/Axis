#include "pch.h"
#include "OpenGLContext.h"
#include "glad/glad.h"

namespace Axis
{
	OpenGLContext::OpenGLContext(GLFWwindow* window)
		: m_window(window)
	{
		AX_ASSERT(m_window, "GLFW window not initialized");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_window);
		int status = gladLoadGL();
		AX_ASSERT(status, "GLAD window not initialized");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_window);
	}
}