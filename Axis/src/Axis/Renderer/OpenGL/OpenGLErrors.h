#pragma once
#include <glad/glad.h>

const char* GL_returnErrorMessage(GLenum error);

void GL_GetError();
bool GL_CheckError(const char* file, int line);

#ifdef _DEBUG || AX_DEBUG
	#define GLASSERT(X) if (!(X)) __debugbreak();
	#define AXIS_GL_ASSERT(X) GL_GetError(); X; GLASSERT(GL_CheckError(__FILE__, __LINE__))
	#define AXIS_GL_ASSERT_INT(X) X; GL_GetError(); X; GLASSERT(GL_CheckError(__FILE__, __LINE__))
#else
	#define AXIS_GL_ASSERT(X) X
	#define AXIS_GL_ASSERT_INT(X) X
#endif