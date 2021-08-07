#include "pch.h"
#include "OpenGLErrors.h"

#include <glad/glad.h>

namespace Axis
{
	const char* GL_returnErrorMessage(uint32_t error)
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

	int GlClearErrors(int var)
	{
		while (glGetError() != GL_NO_ERROR);
		return var;
	}

	bool GlLogCall(const char* function, const char* file, int line)
	{
		if (uint32_t error = glGetError())
		{
			AX_CORE_ERROR("{0} {1} {2} {3} {4} {5} {6}", "[OpenGL Error]", GL_returnErrorMessage(error),
				"in function", function, file, " at line ", line);

			return false;
		}
		return true;
	}
}