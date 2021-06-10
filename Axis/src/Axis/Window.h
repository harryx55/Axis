#pragma once
#include "pch.h"

#include "Core.h"
#include "Events/Events.h"


namespace Axis
{
	struct WindowProps
	{
		std::string title;
		uint32_t width, height;

		WindowProps(std::string a_title = "Axis",
			uint32_t a_width = 1280, uint32_t a_height = 720)
			: title(a_title), width(a_width), height(a_height)
		{
		}
	};
}