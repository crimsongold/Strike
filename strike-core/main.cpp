#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/math/math.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

int main()
{
	using namespace strike;
	using namespace graphics;
	using namespace math;

	Window window("Strike", 960, 540);
	// glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

#if 0
	GLfloat vertices[] =
	{
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#else
	GLfloat vertices[] =
	{
		0, 0, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLushort indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	GLfloat colorsA[] =
	{
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};

	GLfloat colorsB[] =
	{
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1
	};

	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indices, 6);

	sprite1.addBuffers(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.addBuffers(new Buffer(colorsA, 4 * 4, 4), 1);

	sprite2.addBuffers(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.addBuffers(new Buffer(colorsB, 4 * 4, 4), 1);

#endif

	Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4f("pr_matrix", ortho);
	shader.setUniformMat4f("ml_matrix", Mat4::translation(Vec3(4, 3, 0)));

	shader.setUniformVec2f("light_pos", Vec2(4.0f, 1.5f));
	shader.setUniformVec4f("colour", Vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniformVec2f("light_pos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);
#else
		sprite1.bind();
		ibo.bind();
		shader.setUniformMat4f("ml_matrix", Mat4::translation(Vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.bind();
		sprite1.unbind();

		sprite2.bind();
		ibo.bind();
		shader.setUniformMat4f("ml_matrix", Mat4::translation(Vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.bind();
		sprite2.unbind();
#endif
		window.update();
	}

	return 0;
}