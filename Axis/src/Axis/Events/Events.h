#pragma once


#include "Core.h"


namespace Axis
{
	enum class EventType
	{
		None				= 0,	WindowClose			= 1,
		WindowResize		= 2,	WindowMoved			= 3,
		AppUpdate			= 4,	AppRender			= 5,
		KeyPressed			= 6,	KeyReleased			= 7,
		MouseOnClicked		= 8,	MouseOnReleased		= 9,
		MouseMoved			= 10,	MouseScrolled		= 11
	};
}


