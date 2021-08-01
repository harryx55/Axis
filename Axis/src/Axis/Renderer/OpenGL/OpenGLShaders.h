#pragma once

// #include <optional>
// #include <string>
#include "glm/glm.hpp"

namespace Axis
{
	class OpenGLShaders
	{
	public:
		OpenGLShaders(const char*, const char*);
		virtual ~OpenGLShaders();

		void bind() const;
		void unbind() const;

		void SetTexture(const char*, int i = 0);
		void SetUnifromVector3(const char*, const glm::vec3&);
		void SetUnifromMatrix4(const char*, const glm::mat4&);

	private:
		unsigned int m_shaderProgram;
		unsigned int m_vertexShader;
		unsigned int m_fragmentShader;

	private:
		int GetUniformLocation(const std::string&);
		std::optional<std::string> ReadShaderSource(const char*);
	};
}