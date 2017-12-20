#pragma once
#include "System.hpp"
#include "Screen.hpp"
#include <list>
#include "Log.hpp"
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
	protected:
		std::list<Screen*> _screenStack;
		std::list<System*> _appSystems;
		Screen* _activeScreen;
		Log* _engine_log;
	};
}