#include "System.hpp"

namespace Majestic
{
	System::System()
	{
		_name = "";
	}
	System::~System()
	{

	}
	int System::Init()
	{
		return 1;
	}
	int System::Shutdown()
	{
		return 1;
	}
	int System::Reload()
	{
		return 1;
	}

	int System::PushEvent(Event e)
	{
		_events.push_back(e);
		return 1;
	}
	std::string System::GetName()
	{
		return _name;
	}

	void System::SetName(std::string name)
	{
		_name = name;
	}
}