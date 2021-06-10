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

		WindowsWindow* Create(const WindowProps&);
		void onUpdate();
		void SetVSync(bool enabled);


		_Always_((aways_line)) unsigned int GetWidth()  const { return m_data.width; }
		_Always_((aways_line)) unsigned int GetHeight() const { return m_data.height; }

	private:
		void Init(const WindowProps&);
		void ShutDown();

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