#pragma once


#ifdef AXIS_PLATFORM_WINDOWS
	#ifdef AXIS_BUILD_DLL
		#define AXIS_API __declspec(dllexport)
	#else
		#define AXIS_API __declspec(dllimport)
	#endif
#else
	#error Axis is only supported on windows
#endif