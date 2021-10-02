#pragma once
#include "glm/glm.hpp"
#include "OpenGL.h"

namespace Axis
{
	struct OpenGLShaders {
		OpenGLShaders(const char*, const char*);
		virtual ~OpenGLShaders();

		void bind() const;
		void unbind() const;

		void SetTexture(const char*, GLint i = 0);
		void SetUnifromVector3(const char*, const glm::vec3&);
		void SetUnifromMatrix4(const char*, const glm::mat4&);

	private:
		GLuint m_shaderProgram;
		GLuint m_vertexShader;
		GLuint m_fragmentShader;

		int GetUniformLocation(const char* name);
	};
}


