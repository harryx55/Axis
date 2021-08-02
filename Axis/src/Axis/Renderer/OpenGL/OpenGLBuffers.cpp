#include "pch.h"
#include "OpenGLBuffers.h"
#include "OpenGLErrors.h"


namespace Axis
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(void* vertices, GLuint size)
		: vbo(0)
	{
		AXIS_GL_ASSERT(glGenBuffers(1, &vbo));
		AXIS_GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, vbo));
		AXIS_GL_ASSERT(glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW));
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		AXIS_GL_ASSERT(glDeleteBuffers(1, &vbo));
	}

	void OpenGLVertexBuffer::bind() const
	{
		AXIS_GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, vbo));
	}

	void OpenGLVertexBuffer::unbind() const
	{
		AXIS_GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}



	OpenGLIndexBuffer::OpenGLIndexBuffer(void* indices, GLuint size)
		: ibo(0)
	{
		AXIS_GL_ASSERT(glGenBuffers(1, &ibo));
		AXIS_GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
		AXIS_GL_ASSERT(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW));
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		AXIS_GL_ASSERT(glDeleteBuffers(1, &ibo));
	}

	void OpenGLIndexBuffer::bind() const
	{
		AXIS_GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	}

	void OpenGLIndexBuffer::unbind() const
	{
		AXIS_GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

}