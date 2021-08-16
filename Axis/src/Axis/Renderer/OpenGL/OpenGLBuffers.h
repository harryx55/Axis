#pragma once
#include <glad/glad.h>


namespace Axis
{
	struct OpenGLBufferObject
	{
		void CreateVertexArray();
		void BindVertexArray();
		void CreateVertexBuffer(GLuint count, void* data);
		void BindVertexBuffer();
		void CreateIndexBuffer(GLuint count, void* data);
		void BindIndexBuffer();

		void AttachbufferLayout(GLuint index, GLuint size, GLuint stride);

	public:
		GLuint indexCount;
	
	private:
		GLuint vao;
		GLuint vbo;
		GLuint ibo;

		static GLuint offset;
	};
}