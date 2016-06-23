#pragma once

#include "buffers/buffer.h"
#include "buffers/indexBuffer.h"
#include "buffers/vertexArray.h"
#include "../math/math.h"
#include "shader.h"

namespace strike { namespace graphics
{
	
	class Renderable2D
	{
	protected:
		math::Vec2 m_Size;
		math::Vec3 m_Position;
		math::Vec4 m_Color;

		Shader m_Shader;
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;

	public:
		Renderable2D(math::Vec2 a_Size, math::Vec3 a_Position, math::Vec4 a_Color, Shader a_Shader)
			: m_Size(a_Size), m_Position(a_Position), m_Color(a_Color), m_Shader(a_Shader)
		{
			m_VertexArray = new VertexArray();
			GLfloat vertices[] = 
			{
				0, 0, 0,
				0, a_Size.y, 0,
				a_Size.x, a_Size.y, 0,
				a_Size.x, 0, 0
			};

			GLfloat colors[] =
			{
				a_Color.x, a_Color.y, a_Color.z, a_Color.w,
				a_Color.x, a_Color.y, a_Color.z, a_Color.w,
				a_Color.x, a_Color.y, a_Color.z, a_Color.w,
				a_Color.x, a_Color.y, a_Color.z, a_Color.w
			};

			GLushort indices[] =
			{
				0, 1, 2, 
				2, 3, 0
			};

			m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			m_IndexBuffer = new IndexBuffer(indices, 6);
		}

		virtual ~Renderable2D()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}

		inline const VertexArray* getVAO() const{ return m_VertexArray; }
		inline const IndexBuffer* getIBO() const{ return m_IndexBuffer; }

		inline Shader getShader() const { return m_Shader; }
		inline const math::Vec2& getSize() const { return m_Size; }
		inline const math::Vec3& getPosition() const { return m_Position; }
		inline const math::Vec4& getColor() const { return m_Color; }

	};

} }