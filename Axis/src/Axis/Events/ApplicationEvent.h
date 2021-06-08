#pragma once

#include <Events/Events.h>



namespace Axis
{
	struct WindowResizeEvent
	{
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_width(width), m_height(height)
		{
		}

		EventType GetEventType()
		{

		}

		const char* GetEventName()
		{

		}

		static EventType GetEventType() { return EventType::WindowResize; }
		static const char* GetEventName() { return "Window Resize"; }

		unsigned int m_width, m_height;
		bool EventHandled = false;
	};

	struct WindowCloseEvent
	{
		WindowCloseEvent() = default;

		static EventType GetEventType() { return EventType::WindowClose ; }
		static const char* GetEventName() { return "Window Close"; }
	};

	struct WindowMoveEvent
	{
		WindowMoveEvent() = default;

		static EventType GetEventType() { return EventType::WindowMoved; }
		static const char* GetEventName() { return "Window Move"; }

		//unsigned int xpos, ypos;
	};

	struct AppUpdate
	{
		AppUpdate() = default;

		static EventType GetEventType() { return EventType::AppUpdate; }
		static const char* GetEventName() { return "Application update"; }
	};

	struct AppRender
	{
		AppRender() = default;

		static EventType GetEventType() { return EventType::AppRender; }
		static const char* GetEventName() { return "Application Render"; }
	};
}


// virtual ~Event() = default;
// 
// bool Handled = false;
// 
// virtual EventType GetEventType() const = 0;
// virtual const char* GetName() const = 0;
// virtual int GetCategoryFlags() const = 0;
// virtual std::string ToString() const { return GetName(); }