#pragma once
#include "glm/glm.hpp"
#include "OpenGL/OpenGLBuffers.h"


namespace Axis
{
	struct RenderCommand
	{
		static void Clear();
		static void ClearColor(const glm::vec4& color);
		static void DrawIndexed(OpenGLBufferObject* buffer);
	};
}