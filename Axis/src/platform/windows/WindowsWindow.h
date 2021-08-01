#pragma once
#include "pch.h"
#include "Window.h"
#include "GLFW/glfw3.h"

namespace Axis
{
	class WindowsWindow
	{
	public:
		WindowsWindow(const WindowProps&);
		~WindowsWindow();

		void onUpdate();
		void SetVSync(bool enabled);

		GLFWwindow* GetWindow()		const { return m_window;		}
		unsigned int GetWidth()		const { return m_data.width;	}
		unsigned int GetHeight()	const { return m_data.height;	}

	private:
		void Init(const WindowProps&);

	private:
		GLFWwindow* m_window;

		struct WindowData
		{
			std::string title;
			uint32_t width, height;
			bool VSync;
		};

		WindowData m_data;
	};
}
