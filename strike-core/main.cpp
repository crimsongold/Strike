#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/math/math.h"
#include "src/utils/fileutils.h"

int main(int argc, char **argv)
{
	using namespace strike;
	using namespace graphics;
	using namespace math;

	Window window("SparkLight", 800, 600);
	glClearColor(0.2f, 0.7f, 0.3f, 1.0f);

	GLfloat vertices[] =
	{
		4, 3, 0,
		12, 3, 0,
		4, 6, 0,
		4, 6, 0,
		12, 6, 0,
		12, 3, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4f("pr_matrix", ortho);
	shader.setUniformMat4f("ml_matrix", Mat4::translation(Vec3(2, 2, 0)));


	while (!window.closed())
	{
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}

	return 0;
}