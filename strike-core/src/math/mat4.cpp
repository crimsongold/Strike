#include "mat4.h"

#define _USE_MATH_DEFINES
namespace strike { namespace math
{
	
	Mat4::Mat4()
	{
		for (int i=0; i < 4*4; i++)
		{
			m_Elements[i] = 0.0f;
		}
	}

	Mat4::Mat4(float a_Diagonal)
	{
		for (int i = 0; i < 4 * 4; i++)
		{
			m_Elements[i] = 0.0f;
		}

		m_Elements[0 + 0 * 4] = a_Diagonal;
		m_Elements[1 + 1 * 4] = a_Diagonal;
		m_Elements[2 + 2 * 4] = a_Diagonal;
		m_Elements[3 + 3 * 4] = a_Diagonal;

	}

	Mat4 Mat4::identity()
	{
		return Mat4(1.0f);
	}

	//Column Major --> row + column * 4
	Mat4& Mat4::multiply(const Mat4& a_Other)
	{
		Mat4 result;

		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				for (int element = 0; element < 4; element++)
				{
					sum += m_Elements[x + element * 4];
				}
				m_Elements[x + y * 4] = sum;
			}
		}

		return *this;
	}

	Mat4 operator*(Mat4 a_Left, const Mat4& a_Right)
	{
		return a_Left.multiply(a_Right);
	}

	Mat4& Mat4::operator*=(const Mat4& a_Other)
	{
		return multiply(a_Other);
	}

	Mat4 Mat4::orthographic(float a_Left, float a_Right, float a_Bottom, float a_Top,
		float a_Near, float a_Far)
	{
		Mat4 result(1.0f);

		result.m_Elements[0 + 0 * 4] = 2.0f / (a_Right - a_Left);
		result.m_Elements[1 + 1 * 4] = 2.0f / (a_Top - a_Bottom);
		result.m_Elements[2 + 2 * 4] = 2.0f / (a_Near - a_Far);

		result.m_Elements[0 + 3 * 4] = (a_Left + a_Right) / (a_Left - a_Right);
		result.m_Elements[1 + 3 * 4] = (a_Bottom + a_Top) / (a_Bottom - a_Top);
		result.m_Elements[2 + 3 * 4] = (a_Far + a_Near) / (a_Far - a_Near);

		return result;
	}
	
	Mat4 Mat4::perspective(float a_Fov, float a_AspectRatio, float a_Near, float a_Far)
	{
		Mat4 result(1.0f);

		float val = 1.0f / (float)tan(toRadians(0.5f * a_Fov));

		float b = (a_Near + a_Far) / (a_Near - a_Far);
		float c = (2.0f * a_Near * a_Far) / (a_Near - a_Far);

		result.m_Elements[0 + 0 * 4] = val / a_AspectRatio;
		result.m_Elements[1 + 1 * 4] = val;
		result.m_Elements[2 + 2 * 4] = (a_Near + a_Far) / (a_Near - a_Far);
		result.m_Elements[2 + 3 * 4] = (2.0f * a_Near * a_Far) / (a_Near - a_Far);
		result.m_Elements[3 + 2 * 4] = -1.0f;

		return result;
	}

	Mat4 Mat4::translation(const Vec3& a_Translation)
	{
		Mat4 result(1.0f);

		result.m_Elements[0 + 3 * 4] = a_Translation.x;
		result.m_Elements[1 + 3 * 4] = a_Translation.y;
		result.m_Elements[2 + 3 * 4] = a_Translation.z;

		return result;
	}

	Mat4 Mat4::rotation(float a_Angle, const Vec3& a_Axis)
	{
		Mat4 result(1.0f);

		float angleInRadians = toRadians(a_Angle);
		float cosine = cos(angleInRadians);
		float sine = sin(angleInRadians);
		float x = a_Axis.x;
		float y = a_Axis.y;
		float z = a_Axis.z;

		result.m_Elements[0 + 0 * 4] = x * (1 - cosine) + cosine;
		result.m_Elements[1 + 0 * 4] = x * y * (1 - cosine) + z * sine;
		result.m_Elements[2 + 0 * 4] = x* z * (1 - cosine) - y * sine;

		result.m_Elements[0 + 1 * 4] = x * y * (1 - cosine) - z * sine;
		result.m_Elements[1 + 1 * 4] = y * (1 - cosine) + cosine;
		result.m_Elements[2 + 1 * 4] = y * z * (1 - cosine) + x * sine;

		result.m_Elements[0 + 2 * 4] = x * z * (1 - cosine) + y * sine;
		result.m_Elements[1 + 2 * 4] = y * z * (1 - cosine) - x * sine;
		result.m_Elements[2 + 2 * 4] = z * (1 - cosine) + cosine;

		return result;
	}

	Mat4 Mat4::scale(const Vec3& a_Scale)
	{
		Mat4 result(1.0f);

		result.m_Elements[0 + 0 * 4] = a_Scale.x;
		result.m_Elements[1 + 1 * 4] = a_Scale.y;
		result.m_Elements[2 + 2 * 4] = a_Scale.z;

		return result;
	}

} }