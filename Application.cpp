#include	"Application.h"
#include	"config.h"
#include	"EventKeyboard.h"

Application::Application()
{
}

Application::~Application()
{
	if (Config::FULLSCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	UnregisterClass(this->applicationName, this->hInstance);
	this->hInstance = NULL;
}


bool Application::Init()
{
	if (!this->CreateAppWindow(L"Foo", Config::WINDOW_POS_X, Config::WINDOW_POS_Y, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT))
	{
		return false;
	}

	return true;
}

void Application::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// Render loop
		}
	}
}

bool Application::CreateAppWindow(WCHAR* title, int x, int y, u_int width, u_int height)
{
	HWND hwnd;
	WNDCLASSEX wc;

	this->applicationName = title;
	this->hInstance = GetModuleHandle(NULL);

	// Window class setup:
	wc.style				= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc			= WndProc;
	wc.cbClsExtra			= 0;
	wc.cbWndExtra			= 0;
	wc.hInstance			= this->hInstance;
	wc.hIcon				= LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm				= wc.hIcon;
	wc.hCursor				= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground		= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName			= NULL;
	wc.lpszClassName		= this->applicationName;
	wc.cbSize				= sizeof(WNDCLASSEX);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"RegisterClassEX() failed", L"Error", MB_OK);
		return false;
	}

	// Fullscreen setup
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (Config::FULLSCREEN)
	{
		DEVMODE ScreenSettings;
		memset(&ScreenSettings, 0, sizeof(DEVMODE));

		ScreenSettings.dmSize				= sizeof(ScreenSettings);
		ScreenSettings.dmPelsWidth			= (u_long)screenWidth;
		ScreenSettings.dmPelsHeight			= (u_long)screenHeight;
		ScreenSettings.dmBitsPerPel			= 32;
		ScreenSettings.dmFields				= DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&ScreenSettings, CDS_FULLSCREEN);
	}
	else
	{
		screenWidth = width;
		screenHeight = height;
	}

	int style = WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX;
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, title, title, style, x, y, screenWidth, screenHeight, NULL, NULL, this->hInstance, NULL);

	if (NULL == hwnd)
	{
		MessageBox(NULL, L"CreateWindowEx() failed", L"Error", MB_OK);
		PostQuitMessage(0);

		return false;
	}

	ShowWindow(hwnd, SW_SHOW);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	return true;
}

LRESULT Application::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		DestroyWindow(hwnd);
		break;
	case WM_KEYDOWN:
		if (VK_ESCAPE == wParam)
		{
			PostQuitMessage(0);
		}
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}

	return 0;
}