#pragma once

#include "layer.h"

namespace strike { namespace graphics
{
	
	class TileLayer : public Layer
	{
	public:
		TileLayer(Shader* shader);
		~TileLayer();
	};

} }