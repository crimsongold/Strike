#include "vec2.h"

namespace strike
{
	namespace math
	{
		Vec2::Vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		Vec2::Vec2(const float& a_X, const float& a_Y)
		{
			x = a_X;
			y = a_Y;
		}

		Vec2& Vec2::add(const Vec2& a_Other)
		{
			x += a_Other.x;
			y += a_Other.y;
			return *this;
		}

		Vec2& Vec2::subtract(const Vec2& a_Other)
		{
			x -= a_Other.x;
			y -= a_Other.y;
			return *this;
		}

		Vec2& Vec2::multiply(const Vec2& a_Other)
		{
			x *= a_Other.x;
			y *= a_Other.y;
			return *this;
		}

		Vec2& Vec2::divide(const Vec2& a_Other)
		{
			x /= a_Other.x;
			y /= a_Other.y;
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
			return x == a_Other.x && y == a_Other.y;
		}

		bool Vec2::operator!=(const Vec2& a_Other)
		{
			return !(*this == a_Other);
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
			return a_Stream << "Vec2 {" << a_Vector.x << ", " << a_Vector.y << "}";
		}
	}
}

