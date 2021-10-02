#pragma once


#ifdef AXIS_PLATFORM_WINDOWS
	#if AXIS_DYNAMIC_LINK
		#ifdef AXIS_BUILD_DLL
			#define AXIS_API __declspec(dllexport)
		#else
			#define AXIS_API __declspec(dllimport)
		#endif
	#else
		#define AXIS_API
	#endif
#else
	#error Axis is only supported on windows
#endif

#ifdef AXIS_ENABLE_ASSERT
	#ifdef AX_DEBUG
		#define AX_ASSERT(x, ...) { if((!x)) { AX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
		#define AX_CORE_ASSERT(x, ...) { if((!x)) { AX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#else
		#define AX_ASSERT(x, ...)
		#define AX_CORE_ASSERT(x, ...)
	#endif
#else
	#define AX_ASSERT(x, ...)
	#define AX_CORE_ASSERT(x, ...)
#endif

