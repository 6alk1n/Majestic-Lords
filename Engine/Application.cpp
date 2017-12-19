#include "Application.hpp"
#include "Core.hpp"
namespace Majestic
{
	int Application::Run()
	{
		//Init all systems and log them
		for (auto i = _appSystems.begin(); i != _appSystems.end(); i++)
		{
			_engine_log->Write(2, (*i)->GetName() + "Init - ");
			int initresult = (*i)->Init();
			if (initresult==1)
			{
				_engine_log->WriteLine("Success");
			}
			else
			{
				_engine_log->WriteLine("Failed");
			}
		}
		return 1;
	}

	int Application::AddSystem(System* sys)
	{
		_appSystems.push_back(sys);
		return 1;
	}
}