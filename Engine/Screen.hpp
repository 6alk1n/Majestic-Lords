#pragma once
#include "System.hpp"


const int ScreenStart = 1;
const int ScreenEnd = 2;
const int ScreenReload = 3;
const int ScreenPause = 4;


namespace Majestic
{
	class Screen : public System
	{
	public:
		Screen();
		~Screen();
		virtual int GetScreenState();
		virtual int Draw();
		virtual int Update();
		virtual int SetParentSystem(System*);
	protected:
		System* _parentSystem;
		int _screenState;
	};
}