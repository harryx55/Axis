#include "pch.h"
#include "OpenGLBuffers.h"
#include "OpenGLErrors.h"


namespace Axis
{
	GLuint OpenGLBufferObject::offset;
	void OpenGLBufferObject::CreateVertexArray()
	{
		glGenVertexArrays(1, &vao);
	}

	void OpenGLBufferObject::BindVertexArray()
	{
		glBindVertexArray(vao);
	}

	void OpenGLBufferObject::CreateVertexBuffer(GLuint count, void* data)
	{
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		AXIS_GL_ASSERT(glBufferData(GL_ARRAY_BUFFER, count * sizeof(GL_FLOAT), data, GL_STATIC_DRAW));
	}

	void OpenGLBufferObject::BindVertexBuffer()
	{
		AXIS_GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, vbo));
	}

	void OpenGLBufferObject::CreateIndexBuffer(GLuint count, void* data)
	{
		indexCount = count;

		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		AXIS_GL_ASSERT(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
	}

	void OpenGLBufferObject::BindIndexBuffer()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	}

	void OpenGLBufferObject::AttachbufferLayout(GLuint index, GLuint size, GLuint stride)
	{
		AXIS_GL_ASSERT(glEnableVertexAttribArray(index));
		AXIS_GL_ASSERT(glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(GL_FLOAT),
			(void*)(offset * sizeof(GL_FLOAT))));

		offset += size;
	}
}