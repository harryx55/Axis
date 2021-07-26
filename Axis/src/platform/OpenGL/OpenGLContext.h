#pragma once
#include "Axis/Renderer/GraphicsContext.h"
#include "GLFW/glfw3.h"

namespace Axis
{
	class OpenGLContext : GraphcsContext
	{
	private:
		GLFWwindow* m_window;

	public:
		OpenGLContext(GLFWwindow* window);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	};
}