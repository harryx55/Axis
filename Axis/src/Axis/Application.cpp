#include "pch.h"
#include <Axis/Application.h>


namespace Axis {

	Application::Application()
	{
		m_Window = (WindowsWindow*)malloc(sizeof(WindowsWindow));
		m_Window->Create(props);
	}

	Application::~Application()
	{
		delete m_Window;
	}

	void Application::Run()
	{
		while (running)
		{
			m_Window->onUpdate();
		}
	}
}