//File for log handling

#pragma once

//include for file streams
#include <fstream>
#include <ctime>

namespace Majestic {

	class Log
	{
	public:
		Log(std::ofstream*); //stream
		Log(std::string); //file path
		~Log();
		virtual int Write(std::string);
		virtual int Write(int, std::string);
		virtual int WriteLine(std::string);
		virtual int WriteLine(int, std::string);

	protected:
		int WriteToLog(std::string);
		std::ofstream* logstream;
	};
}