#include "pch.h"
#include "OpenGLErrors.h"


const char* GL_returnErrorMessage(GLenum error)
{
	switch (error)
	{
	case GL_INVALID_ENUM:
		return "INVALID ENUM:";

	case GL_INVALID_VALUE:
		return "INVALID VALUE:";

	case  GL_INVALID_OPERATION:
		return "INVALID OPERATION:";

	case GL_INVALID_FRAMEBUFFER_OPERATION:
		return "INVALIDE FRAMEBUFFER OPERATION:";

	case GL_OUT_OF_MEMORY:
		return "OUT OF MEMMORY:";
	}

return nullptr;
}

void GL_GetError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GL_CheckError(const char* file, int line)
{
	if(GLenum error = glGetError())
	{
		AX_CORE_ERROR("{0} {1} {2} {3} {4}", "[OpenGL Error]", GL_returnErrorMessage(error), file, " at line ", line);
		return false;
	}

	return true;
}