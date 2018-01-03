#include "Application.hpp"
#include "Core.hpp"
#include "EventDefines.hpp"
#include <fstream>
namespace Majestic
{
	Application::Application()
	{
		std::ofstream* _engine_log_stream = new std::ofstream;
		_engine_log_stream->open(_engine_log_path, std::ofstream::out);
		_engine_log = new Log(_engine_log_stream);

		//write start log file lines
		_engine_log->WriteLine("---Majestic-Lords Engine Log---");
		_engine_log->WriteLine("Engine Version: " + std::string(_engine_version));
		_engine_log->Write(1,"Init Engine - ");

		bool initcheck = true;

		//do all other initializations

		if (initcheck)
		{
			_engine_log->WriteLine("Success");
		}
		else
		{
			_engine_log->WriteLine("Failed");
		}
		//Adding systems to app
		Window* newWindow = new Window();
		AddSystem(newWindow);
		_window = newWindow;
		Input* newInput = new Input();
		AddSystem(newInput);
		_input = newInput;
		glutinput = _input;
		Graphics* newGraphics = new Graphics();
		AddSystem(newGraphics);
		_graphics = newGraphics;

		//Set input for window
		_window->_input = _input;

	}
	Application::~Application()
	{
		delete _engine_log;
	}
	int Application::Run()
	{
		return Run(GetModuleHandle(NULL), "", 0);
	}

	int Application::Run(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow)
	{
		//Init all systems and log them
		int goodinit = 1;
		for (auto i = _appSystems.begin(); i != _appSystems.end(); i++)
		{
			//Set window graphics
			if (*i == _graphics)
			{
				_graphics->SetHWND(_window->GetHWND());
			}
			int initresult = (*i)->Init();
			HandleEvents();

			_engine_log->Write(2, (*i)->GetName() + " Init - ");
			if (initresult==1)
			{
				_engine_log->WriteLine("Success");
			}
			else
			{
				goodinit = 0;
				_engine_log->WriteLine("Failed");
			}
		}
		if(goodinit) _engine_log->WriteLine(2, std::string("Application Systems Inited Successfully"));
		else
		{
			_engine_log->WriteLine(2, "Application System Init Failed ");
			return 0;
		}

		//Show Window
		ShowWindow(_window->GetHWND() ,
			nCmdShow);
		UpdateWindow(_window->GetHWND());

		return 1;
	}
	int Application::HandleEvents()
	{
		for (auto i = _events.begin(); i != _events.end(); i++)
		{
			if (i->_event == _EventDefine_Log) //handle log events
			{
				_engine_log->WriteLine(3, i->_eventinfo);
			}
			if (i->_event == _EventDefine_PopScreen)
			{
				PopScreen();
			}
		}
		_events.clear();
		return 1;
	}
	int Application::PushScreen(Screen* scr)
	{
		if (scr)
		{
			_events.push_back(Event(_EventDefine_Log, "Pushing Screen : " + scr->GetName()));
			_screenStack.push_back(scr);
			scr->_parentSystem = this;
			if (_screenStack.size()) _activeScreen = _screenStack.back();
			else _activeScreen = nullptr;
			return 1;
		}
		_events.push_back(Event(_EventDefine_Log, "Pushing Screen Error : Empty"));
		return 0;

	}
	int Application::PopScreen()
	{
		if (_screenStack.size())
		{
			_events.push_back(Event(_EventDefine_Log, "Popping Screen : " + _screenStack.back()->GetName()));
			_screenStack.pop_back();
			if (_screenStack.size()) _activeScreen = _screenStack.back();
			else _activeScreen = nullptr;
			return 1;
		}
		_events.push_back(Event(_EventDefine_Log, "Popping Screen Error : Empty"));
		return 0;
	}
	int Application::AddSystem(System* sys)
	{
		if (sys)
		{
			_events.push_back(Event(_EventDefine_Log, "Adding System : " + sys->GetName()));
			_appSystems.push_back(sys);
			sys->_parentSystem = this;
			return 1;
		}	
		_events.push_back(Event(_EventDefine_Log, "Adding System Error : Empty"));
		return 0;

	}
	int Application::Shutdown()
	{
		while (_screenStack.size())
		{
			PopScreen();
		}
		HandleEvents();
		return 1;
	}	
	Window* Application::GetWindow()
	{
		return _window;
	}
	Input* Application::GetInput()
	{
		return _input;
	}
}