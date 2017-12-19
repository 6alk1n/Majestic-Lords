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

	std::string System::GetName()
	{
		return _name;
	}
}