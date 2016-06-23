#pragma once

#include "renderable2d.h"

namespace strike
{
	namespace graphics
	{
		class Renderer2D
		{
		protected:
			virtual void submit(const Renderable2D* a_Renderable2D) = 0;
			virtual void flush() = 0;
		};
	}
}

