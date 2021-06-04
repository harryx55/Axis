#pragma once

#include "Core.h"




namespace Axis
{
	class AXIS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}