#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#define WIN32_LEAN_AND_MEAN

#include <string>
#include <windows.h>
#include "MyTypes.h"

class Application
{
public:
	Application();
	~Application();

	bool Init();
	void Run();
private:
	TCHAR* applicationName;
	HINSTANCE hInstance;

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	bool CreateAppWindow(TCHAR* title, int x, int y, u_int width, u_int height);
};

#endif
