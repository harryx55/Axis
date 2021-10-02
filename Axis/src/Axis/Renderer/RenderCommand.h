#pragma once
#include "glm/glm.hpp"
#include "OpenGL/OpenGLBuffers.h"

namespace Axis
{
	enum BUFFER_BIT
	{
		COLOR_BUFFER_BIT = GL_COLOR_BUFFER_BIT,
		DEPTH_BUFFER_BIT = GL_DEPTH_BUFFER_BIT,
		STENCIL_BUFFER_BIT = GL_STENCIL_BUFFER_BIT
	};

	struct RenderCommand
	{
		static void Clear(const glm::vec4& color, GLenum colorBuffer, GLenum depthBuffer = 0, GLenum stencilBuffer = 0, GLint stencilLevel = 0);
		static void DrawIndexed(OpenGLIndexBuffer buffer);
	};
}