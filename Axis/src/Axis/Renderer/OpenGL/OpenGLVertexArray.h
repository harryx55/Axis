#pragma once
#include "OpenGL.h"

namespace Axis
{
	struct OpenGLShaderElements {
		GLuint  index;
		GLsizei size;
		GLsizei stride;
		GLuint  offsetCount;
	};

	struct OpenGLVertexArray
	{
		void CreateVertexArray();
		void Bind() const;
		void Unbind() const;
		void DeleteVertexArray() const;

		void AttachAttribs(OpenGLShaderElements elem);
	private:
		GLuint vao;
	};



	
}