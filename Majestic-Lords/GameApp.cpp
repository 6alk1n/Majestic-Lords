#include "GameApp.hpp" 
#include <Engine/EventDefines.hpp>
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
		//Handle events
		int handleresult = HandleEvents();
		if (handleresult == 0)
		{
			PushEvent(Event(_EventDefine_EventHandlerError, "Application failed to handle events"));
			return 0;
		}

		//Handle last screen
		int updatestate = _activeScreen->Update();
		int drawstate = _activeScreen->Draw();
		_done = true; //test
	}
	return 1;
}