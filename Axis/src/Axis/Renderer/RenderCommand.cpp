#include "pch.h"
#include "RenderCommand.h"

namespace Axis
{
	void RenderCommand::Clear(const glm::vec4& color, GLenum colorBuffer, GLenum depthBuffer, GLenum stencilBuffer, GLint stencilLevel)
	{
		GLenum mask = colorBuffer;
		
		if (depthBuffer) {
			mask |= GL_DEPTH_BUFFER_BIT;
		}

		if (stencilBuffer) {
			mask |= GL_STENCIL_BUFFER_BIT;
			glClearStencil(stencilLevel);
		}

		glClearColor(color.r, color.g, color.b, color.a);
		AXIS_GL_ASSERT(glClear(mask));
	}

	void RenderCommand::DrawIndexed(OpenGLIndexBuffer buffer)
	{
		buffer.Bind();
		AXIS_GL_ASSERT(glDrawElements(GL_TRIANGLES, buffer.GetCount(), GL_UNSIGNED_INT, nullptr));
	}
}