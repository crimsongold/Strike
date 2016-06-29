#pragma once

#include <GL/glew.h>
#include "../math/math.h"
#include "renderable2d.h"

namespace strike { namespace graphics {

	class Renderer2D
	{
	protected:
		std::vector<math::mat4> m_TransformationStack;

		Renderer2D()
		{
			m_TransformationStack.push_back(math::mat4::identity());
		}

	public:
		void push(const math::mat4& matrix, bool override = false)
		{
			if (!override)
			{
				m_TransformationStack.push_back(matrix);
			} else
			{
				m_TransformationStack.push_back(m_TransformationStack.back() * matrix);
			}
		}
		
		virtual void begin() {}
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void end() {}
		virtual void flush() = 0;
	};

} }