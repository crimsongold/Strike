#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace strike { namespace graphics {
	
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
	
	class Window
	{
	private:
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;

		bool m_Keys[MAX_KEYS];
		bool m_Buttons[MAX_BUTTONS];
		double m_X, m_Y;

	public:
		Window(const char *a_Title, int a_Width, int a_Height);
		~Window();
		void clear() const;
		void update();
		bool closed() const;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }

		bool isKeyPressed(unsigned int a_KeyCode);
		bool isButtonPressed(unsigned int a_ButtonCode);
		void getMousePosition(double& a_X, double& a_y);

	private:
		bool init();
		friend void key_callback(GLFWwindow* a_Window, int a_Key, int a_Scancode, int a_Action, int a_Mods);
		friend void button_callback(GLFWwindow* a_Window, int a_Button, int a_Action, int a_Mods);
		friend void cursor_position_callback(GLFWwindow* a_Window, double a_Xpos, double a_Ypos);
	};
} }