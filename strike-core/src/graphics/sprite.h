#pragma once

#include "renderable2d.h"

namespace strike { namespace graphics
{
	
	class Sprite : public Renderable2D
	{
	private:

	public:
		Sprite(float a_X, float a_Y, float a_Width, float a_Height, math::Vec4& a_Color);
		~Sprite();
	};

} }