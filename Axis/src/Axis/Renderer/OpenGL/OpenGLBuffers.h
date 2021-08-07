#pragma once
#include <glad/glad.h>


namespace Axis
{
	struct BufferLayout
	{
		static void AttachElement(int index, std::size_t size, int stride);
		
	private:
		static int offset;
	};

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

	class OpenGLVertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void Bind() const;
		void Unbind() const;

	private:
		GLuint vertexArray;
	};
}