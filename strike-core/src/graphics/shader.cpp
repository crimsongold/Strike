#include <vector>
#include <iostream>
#include "shader.h"

namespace strike
{
	namespace graphics
	{
		Shader::Shader(const char* a_VertexPath, const char* a_FragPath)
			: m_VertexPath(a_VertexPath), m_FragPath(a_FragPath)
		{
			m_ShaderID = load();
		}

		Shader::~Shader()
		{
		}

		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
			GLint result;

			std::string vertSourceString = FileUtils::read_file(m_VertexPath);
			const char* vertSource = vertSourceString.c_str();

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader: " << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			/* ------------------------------------------- */

			std::string fragSourceString = FileUtils::read_file(m_FragPath);
			const char* fragSource = fragSourceString.c_str();

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader: " << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return 1;
		}

		GLint Shader::getUniformLocation(const GLchar* a_Name)
		{
			return glGetUniformLocation(m_ShaderID, a_Name);
		}

		void Shader::setUniform1f(const GLchar* a_Name, float a_Value)
		{
			glUniform1f(getUniformLocation(a_Name), a_Value);
		}

		void Shader::setUniform1i(const GLchar* a_Name, int a_Value)
		{
			glUniform1i(getUniformLocation(a_Name), a_Value);
		}

		void Shader::setUniformVec2f(const GLchar* a_Name, const math::Vec2& a_Vector)
		{
			glUniform2f(getUniformLocation(a_Name), a_Vector.x, a_Vector.y);
		}

		void Shader::setUniformVec3f(const GLchar* a_Name, const math::Vec3& a_Vector)
		{
			glUniform3f(getUniformLocation(a_Name), a_Vector.x, a_Vector.y, a_Vector.z);
		}

		void Shader::setUniformVec4f(const GLchar* a_Name, const math::Vec4& a_Vector)
		{
			glUniform4f(getUniformLocation(a_Name), a_Vector.x, a_Vector.y, a_Vector.z, a_Vector.w);
		}

		void Shader::setUniformMat4f(const GLchar* a_Name, const math::Mat4& a_Matrix)
		{
			glUniformMatrix4fv(getUniformLocation(a_Name), 1, GL_FALSE, a_Matrix.m_Elements);
		}

		void Shader::enable() const
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}
	}
}

