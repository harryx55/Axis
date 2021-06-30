#pragma once
#include "Core.h"
#include "Input.h"


namespace Axis
{
	class WindowsInput : public IInput
	{
	protected:
		// WindowsInput Get() { return s_instance; }

		bool IsKeyPressedImpl(int keyCode) override;
		bool IsMouseButtonPressedImpl(int button) override;

		std::pair<float, float> GetMousePosImpl() override;
		float GetMousePosXImpl() override;
		float GetMousePosYImpl() override;
	};
}