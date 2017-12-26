//Majestic-Lords Engine Core
#pragma once
//include windows headers
#if defined _WIN64 || defined _WIN32
	#include <Windows.h>
#endif
#include <SDL\SDL.h>
//include logging header
//#include "Log.hpp"
namespace Majestic {

	static const char* _engine_version = "1a";
	static const char* _engine_log_path = "majesticlog.txt";
	int InitEngine();
	int KillEngine();
}