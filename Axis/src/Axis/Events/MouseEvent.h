#pragma once

#include "Events/Events.h"



namespace Axis
{
	struct MouseClickEvent
	{
	protected:
		MouseClickEvent(const MouseCode button)
			: m_button(button)
		{
		}

		MouseCode m_button;
	};

	struct MouseOnClickedEvent : public MouseClickEvent
	{
		MouseOnClickedEvent(const MouseCode button)
			: MouseClickEvent(button)
		{
		}

		static EventType GetEventType() { return EventType::MouseOnClicked; }
		static const char* GetEventName() { return "Mouse Clicked"; }
	};

	struct MouseOnRelease : public MouseClickEvent
	{
		MouseOnRelease(const MouseCode button)
			: MouseClickEvent(button)
		{
		}

		static EventType GetEventType() { return EventType::MouseOnReleased; }
		static const char* GetEventName() { return "Mouse Released"; }
	};

	struct MouseMoveEvent
	{
		MouseMoveEvent(const float& x, const float& y)
			: m_mouseX(x), m_mouseY(y)
		{
		}

		float m_mouseX, m_mouseY;

		static EventType GetEventType() { return EventType::MouseMoved; }
		static const char* GetEventName() { return "Mouse Moved"; }
	};

	struct MouseScrollEvent
	{
		MouseScrollEvent(const float& mouseOffsetX, const float& mouseOffsetY)
			: m_mouseOffsetX(mouseOffsetX), m_mouseOffsetY(mouseOffsetX)
		{
		}

		float m_mouseOffsetX;
		float m_mouseOffsetY;

		static EventType GetEventType() { return EventType::MouseScrolled; }
		static const char* GetEventName() { return "Mouse Scrolled"; }
	};

	enum MouseCode
	{
		Button0 = 0,		Button1 = 1,
		Button2 = 2,		Button3 = 3,
		Button4 = 4,		Button5 = 5,
		Button6 = 6,		Button7 = 7,
		ButtonLast		= Button7,
		ButtonLeft		= Button0,
		ButtonRight		= Button1,
		ButtonMiddle	= Button2
	};

}