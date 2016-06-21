#pragma once

#include <iostream>

namespace strike { namespace math 
{
	struct Vec2
	{
		float m_X, m_Y;
		
		Vec2();

		Vec2(const float& a_X, const float& a_Y);
		
		Vec2& add(const Vec2& a_Other);
		Vec2& subtract(const Vec2& a_Other);
		Vec2& multiply(const Vec2& a_Other);
		Vec2& divide(const Vec2& a_Other);

		friend Vec2 operator+(Vec2 a_Left, const Vec2& a_Right);
		friend Vec2 operator-(Vec2 a_Left, const Vec2& a_Right);
		friend Vec2 operator*(Vec2 a_Left, const Vec2& a_Right);
		friend Vec2 operator/(Vec2 a_Left, const Vec2& a_Right);

		bool operator==(const Vec2& a_Other);
		bool operator!=(const Vec2& a_Other);

		Vec2& operator+=(const Vec2& a_Other);
		Vec2& operator-=(const Vec2& a_Other);
		Vec2& operator*=(const Vec2& a_Other);
		Vec2& operator/=(const Vec2& a_Other);

		friend std::ostream& operator<<(std::ostream& a_Stream, const Vec2& a_Vector);
	};
} }