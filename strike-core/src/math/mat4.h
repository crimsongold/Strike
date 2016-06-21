#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "math.h"

namespace strike { namespace math
{
	float toRadians(float a_Degrees);

	struct Mat4
	{
		union 
		{
			float m_Elements[4 * 4];
			Vec4 m_Columns[4];
		};

		Mat4();
		Mat4(float diagonal);

		static Mat4 identity();
		
		Mat4& multiply(const Mat4& a_Other);
		friend Mat4 operator*(Mat4 a_Left, const Mat4& a_Right);
		Mat4& operator*=(const Mat4& a_Other);
		
		//Projection Matrices
		static Mat4 orthographic(float a_Left, float a_Right, float a_Bottom, float a_Top,
			float a_Near, float a_Far);
		static Mat4 perspective(float a_Fov, float a_AspectRatio, float a_Near, float a_Far);

		//Translation Matrices
		static Mat4 translation(const Vec3& a_Translation);
		static Mat4 rotation(float a_Angle, const Vec3& a_Axis);
		static Mat4 scale(const Vec3& a_Scale);
	};
} }