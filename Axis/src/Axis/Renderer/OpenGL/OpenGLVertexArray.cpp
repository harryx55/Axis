#include "pch.h"
#include "OpenGLVertexArray.h"


namespace Axis
{
	void OpenGLVertexArray::CreateVertexArray()
	{
		AXIS_GL_ASSERT(glGenVertexArrays(1, &vao));
		AXIS_GL_ASSERT(glBindVertexArray(vao));
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(vao);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::DeleteVertexArray() const
	{
		glDeleteVertexArrays(1, &vao);
	}

	void OpenGLVertexArray::AttachAttribs(OpenGLShaderElements elem)
	{
		AXIS_GL_ASSERT(glEnableVertexAttribArray(elem.index));
		glVertexAttribPointer(elem.index, elem.size, GL_FLOAT, GL_FALSE, sizeof(float) * elem.stride, (void*)(sizeof(float) * elem.offsetCount));
	}
}
