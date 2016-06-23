#include "staticsprite.h"

namespace strike
{
	namespace graphics
	{
		StaticSprite::StaticSprite(float a_X, float a_Y, float a_Width, float a_Height, math::Vec4& a_Color, Shader& a_Shader)
			: Renderable2D(math::Vec2(a_Width, a_Height), math::Vec3(a_X, a_Y, 0), a_Color), m_Shader(a_Shader)
		{
			m_VertexArray = new VertexArray();
			GLfloat vertices[] =
				{
					0, 0, 0,
					0, a_Height, 0,
					a_Width, a_Height, 0,
					a_Width, 0, 0
				};

			GLfloat colors[] =
				{
					a_Color.x, a_Color.y, a_Color.z, a_Color.w,
					a_Color.x, a_Color.y, a_Color.z, a_Color.w,
					a_Color.x, a_Color.y, a_Color.z, a_Color.w,
					a_Color.x, a_Color.y, a_Color.z, a_Color.w
				};

			GLuint indices[] =
				{
					0, 1, 2,
					2, 3, 0
				};

			m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			m_IndexBuffer = new IndexBuffer(indices, 6);
		}

		StaticSprite::~StaticSprite()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}
	}
}

