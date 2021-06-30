#include "Axis.h"
#include "LayerStack.h"
#include "Layer.h"

class ExampleLayer : public Axis::ILayer
{
public:
	ExampleLayer()
		: ILayer("Example")
	{
	}

	void OnUpdate() override
	{
	}
};

class Sandbox : public Axis::Application
{
public:
	Sandbox()
	{
		PushOverlay(new Axis::ImguiLayer());
	}

	~Sandbox()
	{

	}
};


Axis::Application* Axis::CreateApplication()
{
	return new Sandbox();
}
