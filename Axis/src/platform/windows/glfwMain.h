#pragma once
#include "GLFW/glfw3.h"

namespace Axis
{
	class glfwWindow {
	public:
		glfwWindow(uint32_t width, uint32_t height, const char* title);
		~glfwWindow();

		void onUpdate();
		void SetVSync(bool enabled);

	        void calculateDeltaTime();
	        float GetFPS();
	        float GetSeconds() { return m_deltaTime; }
	        float GetMilliseconds() { return m_deltaTime * 1000; }
	  
		GLFWwindow* GetWindow()		const { return m_window; }
		unsigned int GetWidth()		const { return m_width;	 }
		unsigned int GetHeight()	const { return m_height; }

	private:
		GLFWwindow* m_window;

		const char* m_title;
		uint32_t m_width;
		uint32_t m_height;

		bool m_vSync;
	  
	        float m_deltaTime;
	        float m_lastFrame;
	};
}
