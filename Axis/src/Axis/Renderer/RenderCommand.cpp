#include "pch.h"
#include "RenderCommand.h"

#include <glad/glad.h>
#include "OpenGL/OpenGLErrors.h"

namespace Axis
{
	void RenderCommand::Clear()
	{
		
		AXIS_GL_ASSERT(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}

	void RenderCommand::ClearColor(const glm::vec4& color)
	{
		AXIS_GL_ASSERT(glClearColor(color.r, color.g, color.b, color.a));
	}

	void RenderCommand::DrawIndexed(OpenGLBufferObject* buffer)
	{
		buffer->BindVertexArray();
		AXIS_GL_ASSERT(glDrawElements(GL_TRIANGLES, buffer->indexCount, GL_UNSIGNED_INT, nullptr));
	}
}