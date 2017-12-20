#pragma once
#include <Engine/Application.hpp>
using namespace Majestic;
class GameApp :public Application
{
public:
	GameApp();
	~GameApp();
	virtual int Init();
	virtual int Shutdown();
	virtual int Reload();
	virtual int Run();
protected:
	bool _done;
};