#pragma once

#include <GL/glew.h>

namespace strike { namespace graphics
{
	class IndexBuffer
	{
	private:
		GLuint m_BufferID;
		GLuint m_Count;
	public:
		IndexBuffer(GLushort* a_Data, GLsizei a_Count);

		void bind() const;
		void unbind() const;

		inline GLuint getCount() const { return m_Count; }
	};
} }