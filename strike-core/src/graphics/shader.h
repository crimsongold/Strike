#pragma once

#include <GL/glew.h>
#include "../utils/fileutils.h"
#include "../math/math.h"

namespace strike { namespace graphics
{
	
	class Shader
	{
	private:
		GLuint m_ShaderID;
		const char *m_VertexPath, *m_FragPath;
	public:
		Shader(const char* a_VertexPath, const char* a_FragPath);
		~Shader();

		void setUniform1f(const GLchar* a_Name, float a_Value);
		void setUniform1i(const GLchar* a_Name, int a_Value);
		void setUniformVec2f(const GLchar* a_Name, const math::Vec2& a_Vector);
		void setUniformVec3f(const GLchar* a_Name, const math::Vec3& a_Vector);
		void setUniformVec4f(const GLchar* a_Name, const math::Vec4& a_Vector);
		void setUniformMat4f(const GLchar* a_Name, const math::Mat4& a_Matrix);

		void enable() const;
		void disable() const;

	private:
		GLuint load();
		GLint getUniformLocation(const GLchar* a_Name);

	};

} }
