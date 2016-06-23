#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/math/math.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/renderable2d.h"

int main()
{
	using namespace strike;
	using namespace graphics;
	using namespace math;

	Window window("Strike", 960, 540);


	Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4f("pr_matrix", ortho);
	shader.setUniformMat4f("ml_matrix", Mat4::translation(Vec3(4, 3, 0)));

	Renderable2D spriteA(math::Vec2(4 ,4), math::Vec3(5, 5, 0), math::Vec4(1, 0, 1, 1), shader);
	Renderable2D spriteB(math::Vec2(16, 9), math::Vec3(0, 0, 0), math::Vec4(0, 0, 1, 1), shader);
	Simple2DRenderer renderer;


	shader.setUniformVec2f("light_pos", Vec2(4.0f, 1.5f));
	shader.setUniformVec4f("colour", Vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniformVec2f("light_pos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		renderer.submit(&spriteA);
		renderer.submit(&spriteB);
		renderer.flush();

		window.update();
	}

	return 0;
}