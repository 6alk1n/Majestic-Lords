#pragma once
#include "Core.hpp"
#include "Types.hpp"
#include <list>
#include "System.hpp"
/*
Input class is basicaly a cache with functions.
*/
namespace Majestic
{
	//Type for telling what state of key is now
	enum KeyState
	{
		Up,
		Pressed,
		Down,
		Released
	};

	const int KEY_A = 0x41;
	const int KEY_D = 0x44;
	const int KEY_W = 0x57;
	const int KEY_S = 0x53;
	const int KEY_Z = 0x5A;
	const int KEY_X = 0x58;

	const int MOUSE_LEFT = 256;
	const int MOUSE_RIGHT = 258;
	const int MOUSE_MIDDLE = 267;

	class Input : public System
	{
	public:
		//System methods
		Input();
		~Input();
		virtual int Init();
		virtual int Shutdown();
		virtual int Reload();

		//Methods
		bool IsPressed(int key); //checks if pressed button (down or pressed)
		bool OnDown(int key);//checks keyondown event
		bool OnUp(int key);//checks keyonup event
		KeyState GetKey(int key);//get key state
		void Update(); //Updated all keys (down->pressed  up->released)
		void Press(int key);//press key
		void Release(int key);//release key
		void SetMousePos(Vector pos);//set mouse pos
		void SetMousePos(double x, double y);//set mouse pos
		void SetDelta(int x, int y);
		int GetDeltaX();
		int GetDeltaY();
		//Getters
		double GetMouseX();
		double GetMouseY();
		Vector GetMousePos();
		std::list<int> GetPressedKeys();
		void ClearPressedKeys();
		void SetScale(double, double);
	protected:
		KeyState keys[256 + 5];
		double mousex, mousey;
		int deltax, deltay;
		std::list<int> m_pressedkeys;
		double m_scaleWidth, m_scaleHeight;
	};
}