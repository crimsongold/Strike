#pragma once

#include "buffers/buffer.h"
#include "buffers/indexBuffer.h"
#include "buffers/vertexArray.h"
#include "../math/math.h"
#include "shader.h"

namespace strike { namespace graphics
{

	struct VertexData
	{
		math::Vec3 vertex;
		math::Vec4 color;
	};

	class Renderable2D
	{
	protected:
		math::Vec2 m_Size;
		math::Vec3 m_Position;
		math::Vec4 m_Color;

	public:
		Renderable2D(math::Vec2 a_Size, math::Vec3 a_Position, math::Vec4 a_Color)
			: m_Size(a_Size), m_Position(a_Position), m_Color(a_Color) {}

		virtual ~Renderable2D() {}

		inline const math::Vec2& getSize() const { return m_Size; }
		inline const math::Vec3& getPosition() const { return m_Position; }
		inline const math::Vec4& getColor() const { return m_Color; }

	};

} }