#pragma once
#include <Engine/Screen.hpp>
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

};