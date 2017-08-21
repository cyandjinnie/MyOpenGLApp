#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#define WIN32_LEAN_AND_MEAN

#include	<string>
#include	<windows.h>
#include	"Utils/MyTypes.h"
#include	<GL/glew.h>
#include	<GLFW/glfw3.h>
#include	"State/BaseState.h"

class Application
{
public:
	Application();
	Application(const char* title);
	~Application();

	bool Init();
	void Run();
private:
	std::string applicationName;
	GLFWwindow* window;

	void processInput(GLFWwindow* window);

	static void WindowResizeCallback(GLFWwindow* window, int width, int height);
	static void WindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void WindowCursorPosCallback(GLFWwindow* window, double xpos, double ypos);

	bool CreateAppWindow(const char* title, u_int width, u_int height);

	BaseState* CurrentState;
};

#endif
