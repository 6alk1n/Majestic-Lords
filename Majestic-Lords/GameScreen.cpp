#include "GameScreen.hpp"
#include <Engine/EventDefines.hpp>
using namespace Majestic;
GameScreen::GameScreen()
	:Screen()
{
	//empty
}
GameScreen::~GameScreen()
{
	//empty
}
int GameScreen::Init()
{
	//empty
	_window = ((Application*)(_parentSystem))->GetWindow();
	_input = ((Application*)(_parentSystem))->GetInput();
	return 1;
}
int GameScreen::Shutdown()
{
	//empty
	return 1;
}
int GameScreen::Reload()
{
	return 1;
}



int GameScreen::Draw()
{
	return 1;
}
int GameScreen::Update()
{
	if (_input->IsPressed(SDLK_ESCAPE))
		_parentSystem->PushEvent(Event(_EventDefine_PopScreen, "Quit"));
	return 1;
}