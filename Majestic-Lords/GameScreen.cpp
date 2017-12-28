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
	_graphics = ((Application*)(_parentSystem))->_graphics;

	//Resize window
	_window->ResizeScreen(1024, 768);
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
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor4f(1.0f, 0.0f, 0.0f,0.5f);
	glVertex2i(0, 0);
	glColor4f(0.0f, 1.0f, 0.0f,0.5f);
	glVertex2i(0, 120);
	glColor4f(0.0f, 0.0f, 1.0f,0.5f);
	glVertex2i(120, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
	glVertex2i(120, 0);
	glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
	glVertex2i(120, 120);
	glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
	glVertex2i(240, 0);
	glEnd();
	glFlush();
	return 1;
}
int GameScreen::Update()
{
	if (_input->IsPressed(27))
		_parentSystem->PushEvent(Event(_EventDefine_PopScreen, "Quit"));
	return 1;
}