#include	<Windows.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"Input/InputControl.h"
#include	"Application.h"
#include	<GLFW/glfw3.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application* App = new Application("Title");

	if (App->Init())
	{
		App->Run();
	}

	delete App;
}

