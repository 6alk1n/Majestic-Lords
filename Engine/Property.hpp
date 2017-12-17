#pragma once
//Property Class
#include <string>
#include <map>

namespace Majestic {
	
	static int _propertynamesize=30;
	struct Property
	{
	public:
		Property();
		Property(const std::string);
		Property(const double);
		double ToDouble();
		Property& operator=(const Property& other); // copy assignment
		//0 zero - different values; 1 equal values; 2 equal names and values
		int operator==(const Property& other); // compare 

		std::string value;
		std::string name;
	};

	struct PropertyClass
	{
	public:
		std::map<std::string, Property&> property;

		int Add(Property);
		int Add(std::string, double);
		int Add(std::string, std::string);
		int Clear();
		Property& Get(std::string);
		std::string GetString(std::string);
		double GetDouble(std::string);
	};

}
