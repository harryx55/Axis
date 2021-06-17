#include "pch.h"
#include <Axis/Application.h>


namespace Axis {

	Application::Application()
	{
		MainWindow = new WindowsWindow(props);
	}

	Application::~Application()
	{
		delete MainWindow;
	}

	void Application::Run()
	{
		while (!glfwWindowShouldClose(MainWindow->GetWindow()))
		{
			MainWindow->onUpdate();
		}
	}
}