#pragma once
#include "OpenGL.h"

namespace Axis
{
	struct OpenGLVertexBuffer
	{
		void AttachBuffer(float*, GLuint count);
		void Bind() const;
		void UnBind() const;
		void DeleteBuffer() const;

	private:
		GLuint vbo;
	};

	struct OpenGLIndexBuffer
	{
		void AttachBuffer(GLuint*, GLuint _count);
		void Bind() const;
		void UnBind() const;
		void DeleteBuffer() const;
		
		GLsizei GetCount() const { return count; }

	private:
		GLuint ibo;
		GLsizei count;
	};
}