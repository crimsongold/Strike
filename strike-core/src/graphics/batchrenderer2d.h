#pragma once

#include "renderer2d.h"
#include "buffers/vertexArray.h"

namespace strike { namespace graphics {

#define RENDERER_MAX_SPRITES	60000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_MAX_SPRITES * RENDERER_SPRITE_SIZE
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX		0
#define SHADER_COLOR_INDEX		1

		class BatchRenderer2D : Renderer2D
		{
		private:
			GLuint m_VAO, m_VBO;
			IndexBuffer* m_IBO;
			VertexData* m_Buffer;

			GLsizei m_IndexCount;

		public:
			BatchRenderer2D();
			~BatchRenderer2D();

			void begin();
			void submit(const Renderable2D* a_Renderable2D) override;
			void end();
			void flush() override;

		private:
			void init();

		};
} }