#pragma once

#ifdef AXIS_PLATFORM_WINDOWS


extern Axis::Application* Axis::CreateApplication();

int main(int argc, char** argv)
{
	Axis::Log::Init();

	// AX_CORE_INFO("Core Logger Initialized");
	// AX_TRACE("client Logger Initialized");

	auto app = Axis::CreateApplication();
	app->Run();
	delete app;
}


#endif //  AXIS_PLATFORM_WINDOWS