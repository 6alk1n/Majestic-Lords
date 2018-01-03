#include <Engine/Core.hpp>
#include "GameApp.hpp"
#include "GameScreen.hpp"
int CALLBACK WinMain(
	HINSTANCE   hInstance,
	HINSTANCE   hPrevInstance,
	LPSTR       lpCmdLine,
	int         nCmdShow
)
{
	// these next few lines create and attach a console
	// to this process.  note that each process is only allowed one console.
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);
	printf("HELLO!!! I AM THE CONSOLE!");



	GameApp App;
	App.Init();
	GameScreen* gamescreen = new GameScreen();
	gamescreen->SetName("MajesticGame");
	
	App.PushScreen(gamescreen);
	App.Run(hInstance,lpCmdLine,nCmdShow);
//	App.Run();

	App.Shutdown();


	return 1;
}