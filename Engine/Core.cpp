#include "Core.hpp"

namespace Majestic {

	int InitEngine()
	{
		//create log file
		std::ofstream* _engine_log_stream = new std::ofstream;
		_engine_log_stream->open(_engine_log_path, std::ofstream::out);
		_engine_log = new Majestic::Log(_engine_log_stream);

		//write start log file lines
		_engine_log->WriteLine("---Majestic-Lords Engine Log---");
		_engine_log->WriteLine("Engine Version: "+std::string(_engine_version));
		_engine_log->Write(1,"Init Engine - ");

		bool initcheck = true;

		//do all other initializations

		if (initcheck)
		{
			_engine_log->Write("Success");
			return 1;
		}
		else
		{
			_engine_log->Write("Failed");
			return -1;
		}
	}

	int KillEngine()
	{
		delete _engine_log;
		return 1;
	}
}