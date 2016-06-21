#include <iostream>
#include "src/graphics/window.h"

int main(int argc, char **argv)
{
	using namespace strike;
	using namespace graphics;

	Window window("SparkLight", 800, 600);

	glClearColor(0.2f, 0.7f, 0.3f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		window.clear();

		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;
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