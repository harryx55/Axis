#pragma once

namespace Axis
{
	const char* GL_returnErrorMessage(uint32_t error);

	int GlClearErrors(int);
	bool GlLogCall(const char* function, const char* file, int line);

#ifdef AX_DEBUG
	#define GLASSERT(X) if (!(X)) __debugbreak();
	#define AXIS_GL_ASSERT(X) GlClearErrors(NULL); X; GLASSERT(GlLogCall(#X, __FILE__, __LINE__))
#else
	#define AXIS_GL_ASSERT(X) X
#endif
}