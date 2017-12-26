#pragma once
#include "System.hpp"
#include "Screen.hpp"
#include <list>
#include "Log.hpp"

//Systems
#include "Window.hpp"
#include "Input.hpp"
namespace Majestic
{
	class Application :public System
	{
	public:
		Application();
		~Application();
		virtual int Run();
		virtual int AddSystem(System*);
		virtual int PushScreen(Screen*);
		virtual int PopScreen();
		virtual int HandleEvents();
		virtual int Shutdown();
		Window* GetWindow();
		Input* GetInput();
	protected:
		std::list<Screen*> _screenStack;
		std::list<System*> _appSystems;
		Screen* _activeScreen;
		Log* _engine_log;
		Window* _window;
		Input* _input;
	};
}