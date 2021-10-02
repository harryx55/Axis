#include "pch.h"
#include "OpenGL.h"

const char* GL_returnErrorMessage(GLuint error)
{
	switch (error)
	{
		case GL_INVALID_ENUM:						return "INVALID ENUM:";
		case GL_INVALID_VALUE:						return "INVALID VALUE:";
		case  GL_INVALID_OPERATION:					return "INVALID OPERATION:";
		case GL_INVALID_FRAMEBUFFER_OPERATION:		return "INVALIDE FRAMEBUFFER OPERATION:";
		case GL_OUT_OF_MEMORY:						return "OUT OF MEMMORY:";
	}
	return nullptr;
}

bool GlLogCall(const GLchar* function, const GLchar* file, GLuint line)
{
	if (auto error = glGetError())
	{
		AX_CORE_ERROR("{0} {1} {2} {3} {4} {5} {6}", "[OpenGL Error]", GL_returnErrorMessage(error),
			"in function", function, file, " at line ", line);

		return false;
	}
	return true;
}
