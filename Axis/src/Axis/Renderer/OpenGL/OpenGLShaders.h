#pragma once
#include "glm/glm.hpp"
#include <glad/glad.h>

namespace Axis
{
	class OpenGLShaders
	{
	public:
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

	private:
		int GetUniformLocation(const char* name);
		const char* ReadShaderSource(const char*);
	};
}