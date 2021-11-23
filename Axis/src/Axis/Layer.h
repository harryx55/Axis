#pragma once
#include "pch.h"

namespace Axis
{
	class ILayer
	{
	public:
		virtual ~ILayer() = default;

		virtual void OnAttach() { }
		virtual void OnDetach() { }
		virtual void OnUpdate(float timestep) { }
		virtual void OnRender() { }
		virtual void OnImguiRender() { }

#ifdef AX_DEBUG
		ILayer(char* name) : m_name(name) { }
		const char* GetName() const { return m_name; }
	private:
		char* m_name;
#else
		ILayer(char* name) { }
#endif
	};
}