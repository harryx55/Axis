#pragma once
#include "pch.h"



namespace Axis
{
	class AXIS_API IInput
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_instance->GetMousePosImpl(); }
		inline static float GetMouseX() { return s_instance->GetMousePosXImpl(); }
		inline static float GetMouseY() { return s_instance->GetMousePosYImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int KeyCode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;

		virtual std::pair<float, float> GetMousePosImpl() = 0;
		virtual float GetMousePosXImpl() = 0;
		virtual float GetMousePosYImpl() = 0;
	
	private:
		static IInput* s_instance;
	};
}