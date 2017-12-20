#pragma once
#include "Property.hpp"
#include <list>
namespace Majestic {
	
	struct Event
	{
		Event()
		{
			_event = 0;
			_eventinfo = "";
			_ptr = nullptr;
		}
		Event(int id)
		{
			Event();
			_event = id;
		}
		Event(int id, std::string info)
		{
			_ptr = nullptr;
			_event = id;
			_eventinfo = info;
		}
		Event(std::string info)
		{
			Event();
			_eventinfo = info;
		}
		int _event;
		std::string _eventinfo;
		void* _ptr;
	};

	class System
	{
	public:
		System();
		~System();
		virtual int Init();
		virtual int Shutdown();
		virtual int Reload();
		virtual int PushEvent(Event);
		std::string GetName();
		void SetName(std::string);
	protected:
		PropertyClass _property;
		std::string _name;
		std::list<Event> _events;
	};
}