#include "src/graphics/window.h"
#include "src/math/math.h"

int main(int argc, char **argv)
{
	using namespace strike;
	using namespace graphics;
	using namespace math;

	Window window("SparkLight", 800, 600);
	

	glClearColor(0.2f, 0.7f, 0.3f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Vec2 vector(1.0f, 2.0f);
	vector.add(Vec2(5.0f, 2.0f));
	std::cout << vector << std::endl;

	while (!window.closed())
	{
		window.clear();

		/*glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();*/
		window.update();
	}

	return 0;
}