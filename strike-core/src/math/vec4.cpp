#include "vec4.h"

namespace strike {
	namespace math
	{
		Vec4::Vec4()
		{
			m_X = 0.0f;
			m_Y = 0.0f;
			m_Z = 0.0f;
			m_W = 0.0f;
		}

		Vec4::Vec4(const float& a_X, const float& a_Y, const float& a_Z, const float& a_W)
		{
			m_X = a_X;
			m_Y = a_Y;
			m_Z = a_Z;
			m_W = a_W;
		}

		Vec4& Vec4::add(const Vec4& a_Other)
		{
			m_X += a_Other.m_X;
			m_Y += a_Other.m_Y;
			m_Z += a_Other.m_Z;
			m_W += a_Other.m_W;
			return *this;
		}

		Vec4& Vec4::subtract(const Vec4& a_Other)
		{
			m_X -= a_Other.m_X;
			m_Y -= a_Other.m_Y;
			m_Z -= a_Other.m_Z;
			m_W -= a_Other.m_W;
			return *this;
		}

		Vec4& Vec4::multiply(const Vec4& a_Other)
		{
			m_X *= a_Other.m_X;
			m_Y *= a_Other.m_Y;
			m_Z *= a_Other.m_Z;
			m_W *= a_Other.m_W;
			return *this;
		}

		Vec4& Vec4::divide(const Vec4& a_Other)
		{
			m_X /= a_Other.m_X;
			m_Y /= a_Other.m_Y;
			m_Z /= a_Other.m_Z;
			m_W /= a_Other.m_W;
			return *this;
		}

		Vec4& operator+(Vec4 a_Left, const Vec4& a_Right)
		{
			return a_Left.add(a_Right);
		}

		Vec4& operator-(Vec4 a_Left, const Vec4& a_Right)
		{
			return a_Left.subtract(a_Right);
		}

		Vec4& operator*(Vec4 a_Left, const Vec4& a_Right)
		{
			return a_Left.multiply(a_Right);
		}

		Vec4& operator/(Vec4 a_Left, const Vec4& a_Right)
		{
			return a_Left.divide(a_Right);
		}

		bool Vec4::operator==(const Vec4& a_Other)
		{
			return m_X == a_Other.m_X && m_Y == a_Other.m_Y && m_Z == a_Other.m_Z && m_W == a_Other.m_W;
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
			return a_Stream << "Vec4 {" << a_Vector.m_X << ", " << a_Vector.m_Y << ", " <<
				a_Vector.m_Z << ", " << a_Vector.m_W <<"}";
		}
	}
}