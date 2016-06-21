#pragma once

#include <iostream>

namespace strike {
	namespace math
	{
		struct Vec4
		{
			float m_X, m_Y, m_Z, m_W;

			Vec4();

			Vec4(const float& a_X, const float& a_Y, const float& a_Z, const float& a_W);

			Vec4& add(const Vec4& a_Other);
			Vec4& subtract(const Vec4& a_Other);
			Vec4& multiply(const Vec4& a_Other);
			Vec4& divide(const Vec4& a_Other);

			friend Vec4& operator+(Vec4& a_Left, const Vec4& a_Right);
			friend Vec4& operator-(Vec4& a_Left, const Vec4& a_Right);
			friend Vec4& operator*(Vec4& a_Left, const Vec4& a_Right);
			friend Vec4& operator/(Vec4& a_Left, const Vec4& a_Right);

			bool operator==(const Vec4& a_Other);
			bool operator!=(const Vec4& a_Other);

			Vec4& operator+=(const Vec4& a_Other);
			Vec4& operator-=(const Vec4& a_Other);
			Vec4& operator*=(const Vec4& a_Other);
			Vec4& operator/=(const Vec4& a_Other);

			friend std::ostream& operator<<(std::ostream& a_Stream, const Vec4& a_Vector);
		};
	}
}