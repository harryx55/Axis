#pragma once
#include "pch.h"

namespace Axis
{
	class Layer
	{
	public:
		virtual ~Layer() = default;

		virtual void OnAttach() { }
		virtual void OnDetach() { }
		virtual void OnUpdate() { }
		virtual void OnRender() { }

		virtual void OnImguiRender() { }

#ifdef AX_DEBUG
		Layer(char* name) : m_name(name) { }
		const char* GetName() const { return m_name; }
	private:
		char* m_name;
#endif
	};
}