#include "Screen.hpp"
namespace Majestic
{
	Screen::Screen()
		:System()
	{

	}
	Screen::~Screen()
	{
		
	}
	int Screen::GetScreenState()
	{
		return _screenState;
	}
	int Screen::Draw() 
	{
		return 1;
	}
	int Screen::Update()
	{
		return 1;
	}
	int Screen::SetParentSystem(System* parent)
	{
		_parentSystem = parent;
		return 1;
	}
}