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
	GameScreen* gamescreen2 =new GameScreen();
	gamescreen2->SetName("MajesticGame SUPER");
	
	App.PushScreen(gamescreen);
	App.PushScreen(gamescreen2);
	App.Run();

	App.Shutdown();


	return 1;
}