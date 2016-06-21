#include "window.h"

namespace strike { namespace graphics
{
	void window_resize(GLFWwindow* a_Window, int a_Width, int a_Height);
	void key_callback(GLFWwindow* a_Window, int a_Key, int a_Scancode, int a_Action, int a_Mods);
	void button_callback(GLFWwindow* a_Window, int a_Button, int a_Action, int a_Mods);
	void cursor_position_callback(GLFWwindow* a_Window, double a_Xpos, double a_Ypos);

	Window::Window(const char* a_Title, int a_Width, int a_Height)
	{
		m_Title = a_Title;
		m_Width = a_Width;
		m_Height = a_Height;

		if (!init())
		{
			glfwTerminate();
		}

		for (int i=0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
		}

		for (int i=0; i < MAX_BUTTONS; i++)
		{
			m_Buttons[i] = false;
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
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);



		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW!" << std::endl;
			return false;
		}

		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

		return true;
	}

	bool Window::isKeyPressed(unsigned int a_KeyCode) const
	{
		if (a_KeyCode >= MAX_KEYS)
		{
			return false;
		}
		return m_Keys[a_KeyCode];
	}

	bool Window::isButtonPressed(unsigned a_ButtonCode) const
	{
		if (a_ButtonCode >= MAX_BUTTONS)
		{
			return false;
		}
		return m_Buttons[a_ButtonCode];
	}

	void Window::getMousePosition(double& a_X, double& a_Y) const
	{
		a_X = m_X;
		a_Y = m_Y;
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

	void window_resize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* a_Window, int a_Key, int a_Scancode, int a_Action, int a_Mods)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(a_Window);
		win->m_Keys[a_Key] = a_Action != GLFW_RELEASE;
	}

	void button_callback(GLFWwindow* a_Window, int a_Button, int a_Action, int a_Mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(a_Window);
		win->m_Buttons[a_Button] = a_Action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow* a_Window, double a_Xpos, double a_Ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(a_Window);
		win->m_X = a_Xpos;
		win->m_Y = a_Ypos;
	}

} }
