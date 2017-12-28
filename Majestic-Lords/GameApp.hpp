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

	virtual int Run(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow);

protected:
	bool _done;
};