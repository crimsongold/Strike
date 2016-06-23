#include "tilelayer.h"
#include "../batchrenderer2d.h"

namespace strike { namespace graphics
{
	
	TileLayer::TileLayer(Shader* shader)
		: Layer(new BatchRenderer2D(), shader, math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f)
		)
	{
		m_Shader->enable();
		m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);
	}

	TileLayer::~TileLayer()
	{
	}

} }
