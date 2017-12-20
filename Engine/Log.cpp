#include "Log.hpp"
#include <string>
namespace Majestic
{
#pragma warning(disable : 4996)  
	Log::Log(std::ofstream* stream)
	{
		logstream = stream;
	}

	Log::~Log()
	{
		logstream->close(); //close stream
	}

	Log::Log(std::string filePath)
	{
		//create filestream
		std::ofstream* _engine_log_stream = new std::ofstream;
		_engine_log_stream->open(filePath, std::ofstream::out);
		//use first constructor
		Log::Log(_engine_log_stream);
	}

	int Log::WriteToLog(std::string msg)
	{
		if (logstream == nullptr) return 0;
		(*logstream) << msg.c_str(); //write message to stream
		return 1;
	}

	int Log::Write(std::string msg)
	{
		return Write(0, msg);
	}
	int Log::Write(int level, std::string msg)
	{
		if (level)
		{
			std::time_t now = std::time(NULL);
			std::tm * ptm = std::localtime(&now);
			char buffer[9];
			std::strftime(buffer, 32, "%H:%M:%S", ptm);
			return WriteToLog("["+std::string(buffer)+ std::string("][")+std::to_string(level)+" level]"+msg);
		}
		else
		{
			return WriteToLog(msg);
		}
	}

	int Log::WriteLine(std::string msg)
	{
		return WriteLine(0, msg);
	}
	int Log::WriteLine(int level, std::string msg)
	{
		if (level)
		{
			std::time_t now = std::time(NULL);
			std::tm * ptm = std::localtime(&now);
			char buffer[9];
			std::strftime(buffer, 32, "%H:%M:%S", ptm);

			return WriteToLog("[" +std::string(buffer) +  std::string("][") + std::to_string(level) + " level]" + msg + "\n");
		}
		else
		{
			return WriteToLog(msg + "\n");
		}
	}
}