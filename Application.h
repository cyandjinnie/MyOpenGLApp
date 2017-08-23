#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#define WIN32_LEAN_AND_MEAN

#include <string>
#include <windows.h>
#include "Utils/MyTypes.h"
#include "Utils/Singleton.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include "Utils/Singleton.h"

class BaseState;

class Application : public Singleton
{
public:
	static Application* GetInstance();

	bool Init(const char* applicationname);
	void Run();
	void SetWindowAspectRatio(float windowaspectratio);
	float GetWindowAspectRatio() const;

	GLFWwindow* GetWindowIndex() const;

private:
	Application();
	~Application();

	GLFWwindow* window;
	BaseState* CurrentState;
	float WindowAspectRatio;

	static void WindowResizeCallback	(GLFWwindow* window, int width, int height);
	static void WindowKeyCallback		(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void WindowCursorPosCallback	(GLFWwindow* window, double xpos, double ypos);

	bool CreateAppWindow(const char* title, u_int width, u_int height);
};

#endif
