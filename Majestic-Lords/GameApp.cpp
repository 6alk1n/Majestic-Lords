#include "GameApp.hpp" 
#include <Engine/EventDefines.hpp>
#include <Engine/Core.hpp>
GameApp::GameApp()
	:Application()
{
	//empty
	_done = false;
}
GameApp::~GameApp()
{
	//empty
}
int GameApp::Init()
{
	//empty
	return 1;
}
int GameApp::Shutdown()
{
	//empty
	Application::Shutdown();
	return 1;
}
int GameApp::Reload()
{
	//empty
	return 1;
}
int GameApp::Run()
{
	int appupperrun = Application::Run();
	if (appupperrun == 0)  return 0;

	if(_screenStack.size())
		_activeScreen = _screenStack.back();
	else 
		_activeScreen = nullptr;
	
	if (_activeScreen == nullptr)
	{
		PushEvent(Event(_EventDefine_EventHandlerError, "No starting Screen"));
		return 2;
	}

	int screenres = _activeScreen->Init();
	if (screenres == 0)
	{
		PushEvent(Event(_EventDefine_EventHandlerError, "Failed to Init starting Screen"));
		return 3;
	}

	while (!_done)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				_done = true;
			}
			//User presses a key
			else if (e.type == SDL_KEYDOWN)
			{
				_input->Press(e.key.keysym.sym);
			}
			else if (e.type == SDL_KEYUP)
			{
				_input->Release(e.key.keysym.sym);
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				_input->SetMousePos(e.button.x, e.button.y);
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				_input->Press(e.button.button + 255);

			}
			else if (e.type == SDL_MOUSEBUTTONUP)
			{

				_input->Release(e.button.button + 255);
			}
		}

		//Handle events
		int handleresult = HandleEvents();
		if (handleresult == 0)
		{
			PushEvent(Event(_EventDefine_EventHandlerError, "Application failed to handle events"));
			return 0;
		}

		//Handle last screen
		if (_activeScreen)
		{
			int updatestate = _activeScreen->Update();
			int drawstate = _activeScreen->Draw();
		}
		else _done = true; //end
	}
	return 1;
}