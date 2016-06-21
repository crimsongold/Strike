#include "window.h"

namespace strike { namespace graphics {
	
	void windowResize(GLFWwindow* window, int width, int height);

	Window::Window(const char* a_Title, int a_Width, int a_Height)
	{
		m_Title = a_Title;
		m_Width = a_Width;
		m_Height = a_Height;

		if (!init())
		{
			glfwTerminate();
		}
	}

	Window::~Window()
	{
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW!" << std::endl;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);


		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW!" << std::endl;
			return false;
		}

		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

		return true;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}


	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::closed() const
	{
		return (bool) glfwWindowShouldClose(m_Window);
	}

	void windowResize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
} }
