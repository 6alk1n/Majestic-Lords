#include "GameScreen.hpp"
#include <Engine/EventDefines.hpp>
using namespace Majestic;
GameScreen::GameScreen()
	:Screen()
{
	obj1.size = Vector(50, 50);
	obj1.color = glColor4(1.0, 1.0, 1.0, 1.0);
	obj1.uv = Majestic::Rectangle(0, 1.0, 1.0, 0);

	obj2.size = Vector(50, 50);
	obj2.color = glColor4(1.0, 0.0, 1.0, 1.0);
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
	_camera.SetPos(Vector(0, 0));
	_camera.SetScale(0.0);

	//Create test texture
	
	obj1.texture = _resources.textures->GetTexture("Data/player.png");
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
	//Clear screen
	glClear(GL_COLOR_BUFFER_BIT);

	//Camera translation
	glTranslatef(-_camera.GetPos().x, -_camera.GetPos().y, _camera.GetScale());
	//Draw objects
	obj1.Draw(_graphics);
	obj2.Draw(_graphics);
	
	//Camera detranslation
	//glTranslatef(_camera.GetPos().x, _camera.GetPos().y, -_camera.GetScale());

	return 1;
}
int GameScreen::Update()
{
	if (_input->IsPressed(27)) //exit
		_parentSystem->PushEvent(Event(_EventDefine_PopScreen, "Quit"));

	//move object
	if (_input->IsPressed(KEY_A))
		obj1.pos += Vector(-20, 0.0);
	if (_input->IsPressed(KEY_D))
		obj1.pos += Vector(20, 0.0);
	if (_input->IsPressed(KEY_W))
		obj1.pos += Vector(0.0, 20);
	if (_input->IsPressed(KEY_S))
		obj1.pos += Vector(0.0, -20);

	//center camera on object
	_camera.Center(obj1.pos);

	return 1;
}