#include "vec4.h"

namespace strike {
	namespace math
	{

		Vec4::Vec4(const float& a_X, const float& a_Y, const float& a_Z, const float& a_W)
		{
			x = a_X;
			y = a_Y;
			z = a_Z;
			w = a_W;
		}

		Vec4& Vec4::add(const Vec4& a_Other)
		{
			x += a_Other.x;
			y += a_Other.y;
			z += a_Other.z;
			w += a_Other.w;
			return *this;
		}

		Vec4& Vec4::subtract(const Vec4& a_Other)
		{
			x -= a_Other.x;
			y -= a_Other.y;
			z -= a_Other.z;
			w -= a_Other.w;
			return *this;
		}

		Vec4& Vec4::multiply(const Vec4& a_Other)
		{
			x *= a_Other.x;
			y *= a_Other.y;
			z *= a_Other.z;
			w *= a_Other.w;
			return *this;
		}

		Vec4& Vec4::divide(const Vec4& a_Other)
		{
			x /= a_Other.x;
			y /= a_Other.y;
			z /= a_Other.z;
			w /= a_Other.w;
			return *this;
		}

		Vec4 operator+(Vec4 a_Left, const Vec4& a_Right)
		{
			return a_Left.add(a_Right);
		}

		Vec4 operator-(Vec4 a_Left, const Vec4& a_Right)
		{
			return a_Left.subtract(a_Right);
		}

		Vec4 operator*(Vec4 a_Left, const Vec4& a_Right)
		{
			return a_Left.multiply(a_Right);
		}

		Vec4 operator/(Vec4 a_Left, const Vec4& a_Right)
		{
			return a_Left.divide(a_Right);
		}

		bool Vec4::operator==(const Vec4& a_Other)
		{
			return x == a_Other.x && y == a_Other.y && z == a_Other.z && w == a_Other.w;
		}

		bool Vec4::operator!=(const Vec4& a_Other)
		{
			return !(*this == a_Other);
		}

		Vec4& Vec4::operator+=(const Vec4& a_Other)
		{
			return add(a_Other);
		}

		Vec4& Vec4::operator-=(const Vec4& a_Other)
		{
			return subtract(a_Other);
		}

		Vec4& Vec4::operator*=(const Vec4& a_Other)
		{
			return multiply(a_Other);
		}

		Vec4& Vec4::operator/=(const Vec4& a_Other)
		{
			return divide(a_Other);
		}

		std::ostream& operator<<(std::ostream& a_Stream, const Vec4& a_Vector)
		{
			return a_Stream << "Vec4 {" << a_Vector.x << ", " << a_Vector.y << ", " <<
				a_Vector.z << ", " << a_Vector.w <<"}";
		}
	}
}