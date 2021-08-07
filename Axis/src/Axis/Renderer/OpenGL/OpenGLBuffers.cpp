#include "pch.h"
#include "OpenGLBuffers.h"
#include "OpenGLErrors.h"


namespace Axis
{
	//####################		Buffer Layout Buffer		####################
	int BufferLayout::offset;
	void BufferLayout::AttachElement(int index, std::size_t size, int stride)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
		offset += size;
	}



	//####################		Vertex Buffer		####################
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



	//####################		Index Buffer		####################
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



	//####################		Vertex Array Buffer		####################
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &vertexArray);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &vertexArray);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(vertexArray);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
}