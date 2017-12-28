#pragma once
#include <Engine/Screen.hpp>
#include <Engine/Application.hpp>

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
};