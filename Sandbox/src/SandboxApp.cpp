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

	void OnUpdate(Axis::Timestep timestep) override
	{
		AX_DEBUG_INFO("{0} ms", timestep.GetMilliSeconds());
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
