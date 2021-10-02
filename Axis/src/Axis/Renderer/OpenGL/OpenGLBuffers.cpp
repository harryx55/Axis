#include "pch.h"
#include "OpenGLBuffers.h"


namespace Axis
{
	void OpenGLVertexBuffer::AttachBuffer(float *data, GLuint count)
	{
		AXIS_GL_ASSERT(glGenBuffers(1, &vbo));
		AXIS_GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, vbo));
		AXIS_GL_ASSERT(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, data, GL_STATIC_DRAW));
	}

	void OpenGLVertexBuffer::Bind() const
	{
		AXIS_GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, vbo));
	}

	void OpenGLVertexBuffer::UnBind() const
	{
		AXIS_GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	void OpenGLVertexBuffer::DeleteBuffer() const
	{
		glDeleteBuffers(1, &vbo);
	}
	
	void OpenGLIndexBuffer::AttachBuffer(GLuint *data, GLuint _count)
	{
		count = _count;

		AXIS_GL_ASSERT(glGenBuffers(1, &ibo));
		AXIS_GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
		AXIS_GL_ASSERT(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * _count, data, GL_STATIC_DRAW));
	}

	void OpenGLIndexBuffer::Bind() const
	{
		AXIS_GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	}
	
	void OpenGLIndexBuffer::UnBind() const
	{
		AXIS_GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	void OpenGLIndexBuffer::DeleteBuffer() const
	{
		glDeleteBuffers(1, &ibo);
	}
}