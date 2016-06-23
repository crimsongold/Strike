#pragma once

#include <GL/glew.h>

namespace strike { namespace graphics
{

	class Buffer
	{
	private:
		GLuint m_BufferID;
		GLuint m_ComponentCount;
	public:
		Buffer(GLfloat* a_Data, GLsizei a_Count, GLuint a_ComponentCount);
		~Buffer();

		void bind() const;
		void unbind() const;

		inline GLuint getComponentCount() const { return m_ComponentCount; }
	};
} }
