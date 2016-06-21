#pragma once

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

namespace strike { namespace math {
	inline float toRadians(float a_Degrees)
	{
		return a_Degrees * M_PI / 180.0f;
	}
} }