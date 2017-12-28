#pragma once
#include "System.hpp"
#include "Screen.hpp"
#include <list>
#include "Log.hpp"

//Systems
#include "Window.hpp"
#include "Input.hpp"
#include "Graphics.hpp"

///FOR GLUT
 static Majestic::Input* glutinput;

namespace Majestic
{
	void keyboardfunc(unsigned char key, int x, int y);
	void keyboardfuncUp(unsigned char key, int x, int y);
	class Application :public System
	{
	public:
		Application();
		~Application();
		virtual int Run();
		virtual int Run(HINSTANCE hInstance,LPSTR lpCmdLine,int nCmdShow);
		virtual int AddSystem(System*);
		virtual int PushScreen(Screen*);
		virtual int PopScreen();
		virtual int HandleEvents();
		virtual int Shutdown();
		Window* GetWindow();
		Input* GetInput();
		Window* _window;
		Input* _input;
		Graphics* _graphics;
	protected:
		std::list<Screen*> _screenStack;
		std::list<System*> _appSystems;
		Screen* _activeScreen;
		Log* _engine_log;
	};
}