#pragma once

#ifdef AXIS_PLATFORM_WINDOWS


extern Axis::Application* Axis::CreateApplication();

int main(int argc, char** argv)
{
	Axis::Log::Init();

	auto app = Axis::CreateApplication();
	app->Run();
	delete app;
}


#endif //  AXIS_PLATFORM_WINDOWS