#pragma once

#include <vector>
#include <GL/glew.h>

#include "buffer.h"

namespace strike {  namespace graphics
{
	
	class VertexArray
	{
	private:
		GLuint m_ArrayID;
		std::vector<Buffer*> m_Buffers;

	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* a_Buffer, GLuint a_Index);

		void bind() const;
		void unbind() const;

	};
} }