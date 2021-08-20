
#include "pch.h"
#include "WindowsInput.h"

#include "Application.h"
#include "GLFW/glfw3.h"


namespace Axis
{
	IInput* IInput::s_instance = new WindowsInput();
	bool WindowsInput::IsKeyPressedImpl(int keyCode)
	{
		auto window = Application::Get().GetWindow().GetWindow();
		int state = glfwGetKey(window, keyCode);
		
		return state == GLFW_PRESS || state == GLFW_RELEASE;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = Application::Get().GetWindow().GetWindow();

		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePosImpl()
	{
		auto window = Application::Get().GetWindow().GetWindow();
		double xPos, yPos;

		glfwGetCursorPos(window, &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

	float WindowsInput::GetMousePosXImpl()
	{
		auto [x, y] = GetMousePosImpl();
		return x;
	}

	float WindowsInput::GetMousePosYImpl()
	{
		auto [x, y] = GetMousePosImpl();
		return y;
	}
}
