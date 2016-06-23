#include "vertexArray.h"

namespace strike { namespace graphics
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ArrayID);
	}

	VertexArray::~VertexArray()
	{
		for (int i = 0; i < m_Buffers.size(); i++)
		{
			delete m_Buffers[i];
		}
	}

	void VertexArray::addBuffers(Buffer* a_Buffer, GLuint a_Index)
	{
		bind();
		a_Buffer->bind();

		glEnableVertexAttribArray(a_Index);
		glVertexAttribPointer(a_Index, a_Buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		a_Buffer->unbind();
		unbind();
	}


	void VertexArray::bind() const
	{
		glBindVertexArray(m_ArrayID);
	}

	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}


} }