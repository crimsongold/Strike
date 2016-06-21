#pragma once

#include <iostream>

namespace strike {
	namespace math
	{
		struct Vec3
		{
			float m_X, m_Y, m_Z;

			Vec3();

			Vec3(const float& a_X, const float& a_Y, const float& a_Z);

			Vec3& add(const Vec3& a_Other);
			Vec3& subtract(const Vec3& a_Other);
			Vec3& multiply(const Vec3& a_Other);
			Vec3& divide(const Vec3& a_Other);

			friend Vec3& operator+(Vec3 a_Left, const Vec3& a_Right);
			friend Vec3& operator-(Vec3 a_Left, const Vec3& a_Right);
			friend Vec3& operator*(Vec3 a_Left, const Vec3& a_Right);
			friend Vec3& operator/(Vec3 a_Left, const Vec3& a_Right);

			bool operator==(const Vec3& a_Other);
			bool operator!=(const Vec3& a_Other);

			Vec3& operator+=(const Vec3& a_Other);
			Vec3& operator-=(const Vec3& a_Other);
			Vec3& operator*=(const Vec3& a_Other);
			Vec3& operator/=(const Vec3& a_Other);

			friend std::ostream& operator<<(std::ostream& a_Stream, const Vec3& a_Vector);
		};
	}
}