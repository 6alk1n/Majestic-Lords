#include "Window.hpp"
#include "EventDefines.hpp"
using namespace Majestic;
Window::Window() :System()
{
	_window = nullptr;
	_surface = nullptr;
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
	//Create SDL Window
	_window = SDL_CreateWindow(title.c_str(), 0, 0, w, h, SDL_WINDOW_SHOWN);
	if (_window == NULL)
	{
		//Failed to create
		_parentSystem->PushEvent(Event(_EventDefine_Log, "Failed to Create Window"));
		return -1;
	}
	//Set window surface
	_surface = SDL_GetWindowSurface(_window);
	return 1;
}
int Window::Shutdown()
{
	//Deallocate surface
	if (_surface)
	{
		SDL_FreeSurface(_surface);
		_surface = nullptr;
	}
	//Destroy window
	if (_window)
	{
		SDL_DestroyWindow(_window);
		_window = nullptr;
	}
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
	if (_window)
	{
		SDL_SetWindowSize(_window, w, h);
		return 1;
	}
	else return 0;
}
int Window::RenameWindow(std::string name)
{
	_property.Set("Title", name);
	if (_window)
	{
		SDL_SetWindowTitle(_window, name.c_str());
		return 1;
	}
	return 0;
}
int Window::SetScreenPos(unsigned int x, unsigned int y)
{
	_property.Set("X", x);
	_property.Set("Y", y);
	if (_window)
		SDL_SetWindowPosition(_window, x, y);
	else return 0;
	return 1;
}
int Window::SetVsync(bool flag)
{
	SDL_GL_SetSwapInterval(flag);
	return 1;
}