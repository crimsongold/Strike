#include "vec2.h"

namespace strike { namespace math
{
	Vec2::Vec2()
	{
		m_X = 0.0f;
		m_Y = 0.0f;
	}

	Vec2::Vec2(const float& a_X, const float& a_Y)
	{
		m_X = a_X;
		m_Y = a_Y;
	}

	Vec2& Vec2::add(const Vec2& a_Other)
	{
		m_X += a_Other.m_X;
		m_Y += a_Other.m_Y;
		return *this;
	}

	Vec2& Vec2::subtract(const Vec2& a_Other)
	{
		m_X -= a_Other.m_X;
		m_Y -= a_Other.m_Y;
		return *this;
	}
	
	Vec2& Vec2::multiply(const Vec2& a_Other)
	{
		m_X *= a_Other.m_X;
		m_Y *= a_Other.m_Y;
		return *this;
	}
	
	Vec2& Vec2::divide(const Vec2& a_Other)
	{
		m_X /= a_Other.m_X;
		m_Y /= a_Other.m_Y;
		return *this;
	}

	Vec2 operator+(Vec2 a_Left, const Vec2& a_Right) 
	{
		return a_Left.add(a_Right);
	}

	Vec2 operator-(Vec2 a_Left, const Vec2& a_Right)
	{
		return a_Left.subtract(a_Right);
	}

	Vec2 operator*(Vec2 a_Left, const Vec2& a_Right)
	{
		return a_Left.multiply(a_Right);
	}

	Vec2 operator/(Vec2 a_Left, const Vec2& a_Right)
	{
		return a_Left.divide(a_Right);
	}

	bool Vec2::operator==(const Vec2& a_Other) 
	{
		return m_X == a_Other.m_X && m_Y == a_Other.m_Y;
	}

	bool Vec2::operator!=(const Vec2& a_Other)
	{
		return !(*this==a_Other);
	}

	Vec2& Vec2::operator+=(const Vec2& a_Other)
	{
		return add(a_Other);
	}

	Vec2& Vec2::operator-=(const Vec2& a_Other)
	{
		return subtract(a_Other);
	}
	
	Vec2& Vec2::operator*=(const Vec2& a_Other)
	{
		return multiply(a_Other);
	}

	Vec2& Vec2::operator/=(const Vec2& a_Other)
	{
		return divide(a_Other);
	}

	std::ostream& operator<<(std::ostream& a_Stream, const Vec2& a_Vector)
	{
		return a_Stream << "Vec2 {" << a_Vector.m_X << ", " << a_Vector.m_Y << "}";
	}
} }