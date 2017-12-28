#include "Window.hpp"
#include "EventDefines.hpp"
#include "Types.hpp"

using namespace Majestic;
static Input* _WndProcInput;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CHAR:		
		if (_WndProcInput) _WndProcInput->Press(wParam);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

using namespace Majestic;
Window::Window() :System()
{
	_property.Set("Width", WindowDefaultWidth);
	_property.Set("Height", WindowDefaultHeight);
	_property.Set("Title", WindowDefaultTitle);
	_property.Set("X", 0);
	_property.Set("Y", 0);
	_name = "Window System";
}

Window::~Window()
{
	//empty
}

int Window::Init()
{ 
	if (!_parentSystem) return 0;
	_parentSystem->PushEvent(Event(_EventDefine_Log, "Starting Window Init"));
	double w = _property.GetDouble("Width");
	if (!_property.status) 
	{
		_parentSystem->PushEvent(Event(_EventDefine_Log, "Window Init - No Width! Using default"));
		w = WindowDefaultWidth;
	}
	double h = _property.GetDouble("Height");
	if (!_property.status)
	{
		_parentSystem->PushEvent(Event(_EventDefine_Log, "Window Init - No Height! Using default"));
		h = WindowDefaultHeight;
	}
	std::string title = _property.GetString("Title");
	if (!_property.status)
	{
		_parentSystem->PushEvent(Event(_EventDefine_Log, "Window Init - No Title! Using default"));
		title = WindowDefaultTitle;
	}

	//Set global input
	_WndProcInput = _input;

	int res = InitWindow();
	if (res != 1)
	{
		_parentSystem->PushEvent(Event(_EventDefine_Log, "Failed to Init Window API"));
	}
	if (1 == NULL)
	{
		//Failed to create
		_parentSystem->PushEvent(Event(_EventDefine_Log, "Failed to Create Window"));
		return -1;
	}
	return 1;
}
int Window::Shutdown()
{
	return 1;
}
int Window::Reload()
{
	//empty
	return 1;
}
int Window::ResizeScreen(unsigned int w, unsigned int h)
{
	_property.Set("Width", w);
	_property.Set("Height", h);
	//Resize window
	SetWindowPos(_hwnd, HWND_TOP, 0, 0, w, h,NULL);

	//Resize GL
	glViewport(0, 0,w,h);
	glOrtho(-_property.GetDouble("Width"), _property.GetDouble("Width"), -_property.GetDouble("Height"), _property.GetDouble("Height"), -1.0, 1.0);



	return 0;
}
int Window::RenameWindow(std::string name)
{
	_property.Set("Title", name);

	return 0;
}
int Window::SetScreenPos(unsigned int x, unsigned int y)
{
	_property.Set("X", x);
	_property.Set("Y", y);
	return 1;
}
int Window::SetVsync(bool flag)
{
	return 1;
}
int Window::InitWindow()
{
	std::string title = _property.GetString("Title");
	double w = _property.GetDouble("Width");
	double h = _property.GetDouble("Height");

	///WINAPI
	_hInstance = GetModuleHandle(NULL); //Get current instance

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _hInstance;
	wcex.hIcon = LoadIcon(_hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"Majestic";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		_parentSystem->PushEvent(Event(_EventDefine_Log, "Failed to register class!"));
		return 0;
	}

	_hwnd = CreateWindow(
		L"Majestic",
		widen(title).c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		(int)w, (int)h,
		NULL,
		NULL,
		_hInstance,
		NULL
	); 
	if (!_hwnd)
	{
		_parentSystem->PushEvent(Event(_EventDefine_Log, "Failed to create window class!"));
		return 0;

	}

	return 1;
}
const HINSTANCE Window::GetInstance()
{
	return _hInstance;
}
const HWND Window::GetHWND()
{
	return _hwnd;
}