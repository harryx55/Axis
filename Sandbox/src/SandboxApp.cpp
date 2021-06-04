#include "Axis.h"

class Sandbox : public Axis::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Axis::Application* Axis::CreateApplication()
{
	return new Sandbox();
}
