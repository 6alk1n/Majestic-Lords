//File for log handling

#pragma once

#include "Core.hpp"

#include <sstream>

namespace Majestic {

	class Log
	{
	public:
		Log();
		~Log();
	protected:
		std::ofstream* ofstream;
	};
}