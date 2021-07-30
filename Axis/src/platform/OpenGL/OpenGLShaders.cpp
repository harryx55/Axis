#include "pch.h"
#include "OpenGLShaders.h"
#include <glad/glad.h>

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace Axis
{
	Shaders::Shaders(const char* vertexSrc, const char* fragmentSrc)
	{
		m_shaderProgram = glCreateProgram();
		m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
		m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(m_vertexShader, 1, &vertexSrc, nullptr);
		glCompileShader(m_vertexShader);

		int compileResult = 0;
		glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &compileResult);
		if (compileResult == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(m_vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(m_vertexShader, maxLength, &maxLength, &infoLog[0]);
			AX_CORE_ERROR("{0}, {1} ", "vertex shader compilation failed", infoLog.data());

			glDeleteShader(m_vertexShader);
			return;
		}

		glShaderSource(m_fragmentShader, 1, &fragmentSrc, nullptr);
		glCompileShader(m_fragmentShader);

		compileResult = 0;
		glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &compileResult);
		if (compileResult == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(m_fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(m_fragmentShader, maxLength, &maxLength, &infoLog[0]);
			AX_CORE_ERROR("{0}, {1}", "fragment shader compilation failed", infoLog.data());

			glDeleteShader(m_fragmentShader);
			return;
		}

		glAttachShader(m_shaderProgram, m_vertexShader);
		glAttachShader(m_shaderProgram, m_fragmentShader);
		glLinkProgram(m_shaderProgram);

		int linkResult = 0;
		glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &linkResult);
		if (linkResult == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(m_shaderProgram, maxLength, &maxLength, &infoLog[0]);
			AX_CORE_ERROR("{0}, {1} ", "shader linking failed", infoLog.data());

			glDeleteShader(m_shaderProgram);
			return;
		}

		glValidateProgram(m_shaderProgram);

		glDetachShader(m_shaderProgram, m_vertexShader);
		glDetachShader(m_shaderProgram, m_fragmentShader);
	}

	std::optional<std::string> Shaders::ReadShaderSource(const char* filename)
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

	int Shaders::GetUniformLocation(const std::string& name)
	{
		int location = glGetUniformLocation(m_shaderProgram, name.c_str());

		std::string error_message = "uniform " + name + " does not exist";
		if (location == -1)
			AX_CORE_ERROR(error_message.c_str());
		return location;
	}

	void Shaders::SetTexture(const char* name, int i)
	{
		glUniform1i(GetUniformLocation(name), i);
	}

	void Shaders::SetUnifromVector3(const char* name, const glm::vec3& vector)
	{
		glUniform3fv(GetUniformLocation(name), 1, glm::value_ptr(vector));
	}

	void Shaders::SetUnifromMatrix4(const char* name, const glm::mat4& matrix)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void Shaders::bind() const
	{
		glUseProgram(m_shaderProgram);
	}

	void Shaders::unbind() const
	{
		glUseProgram(0);
	}

	Shaders::~Shaders()
	{
		glDeleteShader(m_vertexShader);
		glDeleteShader(m_fragmentShader);
		glDeleteShader(m_shaderProgram);
	}
}