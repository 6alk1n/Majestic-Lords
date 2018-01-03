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
	return Run(GetModuleHandle(NULL), "", 0);
}
int GameApp::Run(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow)
{	
	///TEMPORARY CODE 
	//Initialize FreeGLUT
	int argc = 0;
	char* args[] = { "" };

	//Create OpenGL 2.1 context

	///END TEMPORARY

	int appupperrun = Application::Run(hInstance,lpCmdLine,nCmdShow);
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
	
	//MAIN LOOP
	MSG msg;
	while (!_done)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			//	while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
			if (msg.message == WM_QUIT)
				break;
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
				SwapBuffers(_graphics->GetHDC());
				//glFinish(); //execute draw commands
			}
			else _done = true; //No more screen
			if (_done) break; //End Application
			_input->Update();
		
		}
	return 1;
}
