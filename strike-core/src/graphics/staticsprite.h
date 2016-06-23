#pragma once

#include "renderable2d.h"

namespace strike
{
	namespace graphics
	{
		class StaticSprite : public Renderable2D
		{
		private:
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
			Shader& m_Shader;

		public:
			StaticSprite(float a_X, float a_Y, float a_Width, float a_Height, math::Vec4& a_Color, Shader& a_Shader);
			~StaticSprite();

			inline const VertexArray* getVAO() const
			{
				return m_VertexArray;
			}

			inline const IndexBuffer* getIBO() const
			{
				return m_IndexBuffer;
			}

			inline Shader getShader() const
			{
				return m_Shader;
			}
		};
	}
}

