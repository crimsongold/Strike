#include "vec3.h"

namespace strike {
	namespace math
	{
		Vec3::Vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		Vec3::Vec3(const float& a_X, const float& a_Y, const float& a_Z)
		{
			x = a_X;
			y = a_Y;
			z = a_Z;
		}

		Vec3& Vec3::add(const Vec3& a_Other)
		{
			x += a_Other.x;
			y += a_Other.y;
			z += a_Other.z;
			return *this;
		}

		Vec3& Vec3::subtract(const Vec3& a_Other)
		{
			x -= a_Other.x;
			y -= a_Other.y;
			z -= a_Other.z;
			return *this;
		}

		Vec3& Vec3::multiply(const Vec3& a_Other)
		{
			x *= a_Other.x;
			y *= a_Other.y;
			z *= a_Other.z;
			return *this;
		}

		Vec3& Vec3::divide(const Vec3& a_Other)
		{
			x /= a_Other.x;
			y /= a_Other.y;
			z /= a_Other.z;
			return *this;
		}

		Vec3 operator+(Vec3 a_Left, const Vec3& a_Right)
		{
			return a_Left.add(a_Right);
		}

		Vec3 operator-(Vec3 a_Left, const Vec3& a_Right)
		{
			return a_Left.subtract(a_Right);
		}

		Vec3 operator*(Vec3 a_Left, const Vec3& a_Right)
		{
			return a_Left.multiply(a_Right);
		}

		Vec3 operator/(Vec3 a_Left, const Vec3& a_Right)
		{
			return a_Left.divide(a_Right);
		}

		bool Vec3::operator==(const Vec3& a_Other)
		{
			return x == a_Other.x && y == a_Other.y && z == a_Other.z;
		}

		bool Vec3::operator!=(const Vec3& a_Other)
		{
			return !(*this == a_Other);
		}

		Vec3& Vec3::operator+=(const Vec3& a_Other)
		{
			return add(a_Other);
		}

		Vec3& Vec3::operator-=(const Vec3& a_Other)
		{
			return subtract(a_Other);
		}

		Vec3& Vec3::operator*=(const Vec3& a_Other)
		{
			return multiply(a_Other);
		}

		Vec3& Vec3::operator/=(const Vec3& a_Other)
		{
			return divide(a_Other);
		}

		std::ostream& operator<<(std::ostream& a_Stream, const Vec3& a_Vector)
		{
			return a_Stream << "Vec3 {" << a_Vector.x << ", " << a_Vector.y << ", " << 
				a_Vector.z << "}";
		}
	}
}