#include "simple2drenderer.h"

namespace strike
{
	namespace graphics
	{
		void Simple2DRenderer::submit(const Renderable2D* a_Renderable)
		{
			m_RenderQueue.push_back((StaticSprite*) a_Renderable);
		}

		void Simple2DRenderer::flush()
		{
			while (!m_RenderQueue.empty())
			{
				const StaticSprite* renderable = m_RenderQueue.front();
				renderable->getVAO()->bind();
				renderable->getIBO()->bind();

				renderable->getShader().setUniformMat4f("ml_matrix", math::Mat4::translation(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

				renderable->getIBO()->unbind();
				renderable->getVAO()->unbind();

				m_RenderQueue.pop_front();
			}
		}
	}
}

