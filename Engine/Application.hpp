#pragma once
#include "System.hpp"
#include "Screen.hpp"
#include <list>
namespace Majestic
{
	class Application :public System
	{
	public:
		virtual int Run();
		virtual int AddSystem(System*);
	protected:
		std::list<Screen*> _screenStack;
		std::list<System*> _appSystems;
		Screen* _activeScreen;
	};
}