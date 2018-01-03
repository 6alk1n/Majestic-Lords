#pragma once
#include <Engine/Screen.hpp>
#include <Engine/Application.hpp>
#include <Engine/Camera.hpp>
#include <Engine/Object.hpp>
using namespace Majestic;
class GameScreen :public Screen
{
public:
	GameScreen();
	~GameScreen();
	virtual int Init();
	virtual int Shutdown();
	virtual int Reload();		
	virtual int Draw();
	virtual int Update();
protected:
	Window* _window;
	Graphics* _graphics;
	Input* _input;
	Camera _camera;
	Object obj1;
	Object obj2;
};