#include "pch.h"

#include <glad/glad.h>
#include "OpenGLShaders.h"
#include "OpenGLErrors.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace Axis
{
	OpenGLShaders::OpenGLShaders(const char* vertexSrc, const char* fragmentSrc)
	{
		m_shaderProgram = AXIS_GL_ASSERT_INT(glCreateProgram());
		m_vertexShader = AXIS_GL_ASSERT_INT(glCreateShader(GL_VERTEX_SHADER));
		m_fragmentShader = AXIS_GL_ASSERT_INT(glCreateShader(GL_FRAGMENT_SHADER));

		AXIS_GL_ASSERT(glShaderSource(m_vertexShader, 1, &vertexSrc, nullptr));
		AXIS_GL_ASSERT(glCompileShader(m_vertexShader));

		int compileResult = 0;
		AXIS_GL_ASSERT(glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &compileResult));
		if (compileResult == GL_FALSE)
		{
			int maxLength = 0;
			AXIS_GL_ASSERT(glGetShaderiv(m_vertexShader, GL_INFO_LOG_LENGTH, &maxLength));

			std::vector<char> infoLog(maxLength);
			AXIS_GL_ASSERT(glGetShaderInfoLog(m_vertexShader, maxLength, &maxLength, &infoLog[0]));
			AX_CORE_ERROR("{0}, {1} ", "vertex shader compilation failed", infoLog.data());

			AXIS_GL_ASSERT(glDeleteShader(m_vertexShader));
			return;
		}

		AXIS_GL_ASSERT(glShaderSource(m_fragmentShader, 1, &fragmentSrc, nullptr));
		AXIS_GL_ASSERT(glCompileShader(m_fragmentShader));

		compileResult = 0;
		AXIS_GL_ASSERT(glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &compileResult));
		if (compileResult == GL_FALSE)
		{
			int maxLength = 0;
			AXIS_GL_ASSERT(glGetShaderiv(m_fragmentShader, GL_INFO_LOG_LENGTH, &maxLength));

			std::vector<char> infoLog(maxLength);
			AXIS_GL_ASSERT(glGetShaderInfoLog(m_fragmentShader, maxLength, &maxLength, &infoLog[0]));
			AX_CORE_ERROR("{0}, {1}", "fragment shader compilation failed", infoLog.data());

			AXIS_GL_ASSERT(glDeleteShader(m_fragmentShader));
			return;
		}

		AXIS_GL_ASSERT(glAttachShader(m_shaderProgram, m_vertexShader));
		AXIS_GL_ASSERT(glAttachShader(m_shaderProgram, m_fragmentShader));
		AXIS_GL_ASSERT(glLinkProgram(m_shaderProgram));

		int linkResult = 0;
		AXIS_GL_ASSERT(glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &linkResult));
		if (linkResult == GL_FALSE)
		{
			int maxLength = 0;
			AXIS_GL_ASSERT(glGetShaderiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &maxLength));

			std::vector<char> infoLog(maxLength);
			AXIS_GL_ASSERT(glGetShaderInfoLog(m_shaderProgram, maxLength, &maxLength, &infoLog[0]));
			AX_CORE_ERROR("{0}, {1} ", "shader linking failed", infoLog.data());

			AXIS_GL_ASSERT(glDeleteShader(m_shaderProgram));
			return;
		}

		AXIS_GL_ASSERT(glValidateProgram(m_shaderProgram));

		AXIS_GL_ASSERT(glDetachShader(m_shaderProgram, m_vertexShader));
		AXIS_GL_ASSERT(glDetachShader(m_shaderProgram, m_fragmentShader));
	}

	std::optional<std::string> OpenGLShaders::ReadShaderSource(const char* filename)
	{
		std::fstream fileStream;
		std::stringstream stringStream;

		fileStream.open(filename);
		if (!fileStream.is_open())
		{
			AX_CORE_ERROR("{0}, {1} ", "could not open shader source file at location ", filename);
			return std::nullopt;
		}

		AX_CORE_INFO("{0}, {1} ", filename, " shader loaded successfully");
		stringStream << fileStream.rdbuf();
		fileStream.close();

		return stringStream.str();
	}

	int OpenGLShaders::GetUniformLocation(const std::string& name)
	{
		int location = AXIS_GL_ASSERT_INT(glGetUniformLocation(m_shaderProgram, name.c_str()));

		std::string error_message = "uniform " + name + " does not exist";
		if (location == -1)
			AX_CORE_ERROR(error_message.c_str());
		return location;
	}

	void OpenGLShaders::SetTexture(const char* name, int i)
	{
		AXIS_GL_ASSERT(glUniform1i(GetUniformLocation(name), i));
	}

	void OpenGLShaders::SetUnifromVector3(const char* name, const glm::vec3& vector)
	{
		AXIS_GL_ASSERT(glUniform3fv(GetUniformLocation(name), 1, glm::value_ptr(vector)));
	}

	void OpenGLShaders::SetUnifromMatrix4(const char* name, const glm::mat4& matrix)
	{
		AXIS_GL_ASSERT(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix)));
	}

	void OpenGLShaders::bind() const
	{
		AXIS_GL_ASSERT(glUseProgram(m_shaderProgram));
	}

	void OpenGLShaders::unbind() const
	{
		AXIS_GL_ASSERT(glUseProgram(0));
	}

	OpenGLShaders::~OpenGLShaders()
	{
		AXIS_GL_ASSERT(glDeleteShader(m_vertexShader));
		AXIS_GL_ASSERT(glDeleteShader(m_fragmentShader));
		AXIS_GL_ASSERT(glDeleteShader(m_shaderProgram));
	}
}