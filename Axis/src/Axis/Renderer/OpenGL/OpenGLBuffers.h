#pragma once

#include <glad/glad.h>

namespace Axis
{
	class OpenGLVertexBuffer
	{
	public:
		OpenGLVertexBuffer(void* vertices, GLuint size);
		~OpenGLVertexBuffer();

		void bind() const;
		void unbind() const;

	private:
		GLuint vbo;
	};

	class OpenGLIndexBuffer
	{
	public:
		OpenGLIndexBuffer(void* indices, GLuint size);
		~OpenGLIndexBuffer();

		void bind() const;
		void unbind() const;

	private:
		GLuint ibo;
	};
}