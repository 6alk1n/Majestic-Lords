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

	GameApp App;
	App.Init();
	GameScreen* gamescreen = new GameScreen();
	gamescreen->SetName("MajesticGame");
	
	App.PushScreen(gamescreen);
	App.Run(hInstance,lpCmdLine,nCmdShow);

	App.Shutdown();


	return 1;
}