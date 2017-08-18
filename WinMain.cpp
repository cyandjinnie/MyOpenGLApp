#include	<Windows.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"InputControl.h"
#include	"Application.h"

#include	<glm.hpp>
#include	<GL\glew.h>
#include	<GLFW\glfw3.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*Application* App = new Application();

	if (App->Init())
	{
		App->Run();
	}

	delete App;*/

	if (!glfwInit())
	{
		fprintf(stderr, "glfwInit() failed");
		return 0;
	}

	return 1;
}

