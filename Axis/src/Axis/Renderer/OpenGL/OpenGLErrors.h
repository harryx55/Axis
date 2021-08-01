#pragma once
#include <glad/glad.h>

const char* GL_returnErrorMessage(GLenum error);

void GL_GetError();
bool GL_CheckError(const char* file, int line);

#define GLASSERT(X) if (!(X)) __debugbreak();
#define AXIS_GL_ERROR(X) GL_GetError(); X; GLASSERT(GL_CheckError(__FILE__, __LINE__))
