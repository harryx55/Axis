#include "pch.h"
#include "glfw.h"


namespace Axis {
  glfwWindow::glfwWindow(uint32_t width, uint32_t height, const char* title, bool fullscreen, bool vsync)
		: m_window(NULL), m_width(width), m_height(height), m_title(title), m_vSync(true) {
		m_title = title;
		m_width = width;
		m_height = height;

		int glfwStatus = glfwInit();
		AX_CORE_ASSERT(glfwStatus, "[ERROR]: GLFW not Initialized");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		
		m_window = glfwCreateWindow(width, height, title, NULL, NULL);
		AX_CORE_ASSERT(m_window, "[ERROR]: GLFW window failed.");

		glfwMakeContextCurrent(m_window);
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* w, int width, int height) {
		    glViewport(0, 0, width, height);
		});

		int gladStatus = gladLoadGL();
		AX_CORE_ASSERT(gladStatus, "[ERROR]: GLAD not Initialized");

		if(vsync) {
		      SetVSync(true);
		}
	}

	glfwWindow::~glfwWindow() {
		glfwTerminate();
	}

	void glfwWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void glfwWindow::SetVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);

		m_vSync = enabled;
	}

	void glfwWindow::calculateDeltaTime() {
		float time =(float)glfwGetTime();
		m_deltaTime = time - m_lastFrame;
		m_lastFrame = time;
	}

	float glfwWindow::GetFPS() {
	        return 1000 / (m_deltaTime * 1000);
	}
}

