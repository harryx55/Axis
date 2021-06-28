#include "Axis.h"
#include "LayerStack.h"
#include "Layer.h"

class ExampleLayer : public Axis::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		AX_INFO("Updating Example Layer");
	}
};

class Sandbox : public Axis::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};


Axis::Application* Axis::CreateApplication()
{
	return new Sandbox();
}
