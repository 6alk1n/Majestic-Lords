#pragma once
#include "Property.hpp"
namespace Majestic {
	class System
	{
	public:
		System();
		~System();
		virtual int Init();
		virtual int Shutdown();
		virtual int Reload();
		std::string GetName();
	protected:
		PropertyClass _property;
		std::string _name;
	};
}