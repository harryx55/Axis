#pragma once
#include "Renderer/OpenGL/GLADGL.h"

const char* GL_returnErrorMessage(GLuint error);
bool GlLogCall(const GLchar* function, const GLchar* file, GLuint line);
/*
void ClearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}
*/

#ifdef AX_DEBUG
	#define AXIS_GL_ASSERT(x) while(glGetError() != GL_NO_ERROR); x; if(!(GlLogCall(#x, __FILE__, __LINE__))) {__debugbreak(); }
#else
	#define AXIS_GL_ASSERT(x) x;
#endif