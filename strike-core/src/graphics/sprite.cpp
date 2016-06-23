#include "sprite.h"

namespace strike
{
	namespace graphics
	{
		Sprite::Sprite(float a_X, float a_Y, float a_Width, float a_Height, math::Vec4& a_Color)
			: Renderable2D(math::Vec2(a_Width, a_Height), math::Vec3(a_X, a_Y, 0), a_Color)
		{
		}

		Sprite::~Sprite()
		{
		}
	}
}

