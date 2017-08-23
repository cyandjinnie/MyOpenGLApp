#include	<Windows.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"Application.h"

#define GLEW_STATIC
#include <GL\glew.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	auto App = Application::GetInstance();

	if (App->Init("MyWindow"))
	{
		App->Run();
	}
}

