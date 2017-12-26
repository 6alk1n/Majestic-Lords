#include "Property.hpp"
#include "Types.hpp"
namespace Majestic {
	Property::Property()
	{
		this->name = "";
		this->value = "";
	
	}
	Property::Property(const std::string val)
	{
		this->name = "";
		this->value = val;
	}
	Property::Property(const double val)
	{
		this->name = "";
		this->value = std::to_string(val);
	}

	double Property::ToDouble()
	{
		return StrToDouble(value);
	}
	Property& Property::operator=(const Property& other)
	{
		this->name = other.name;
		this->value = other.value;
		return *this;
	}
	int Property::operator==(const Property& other)
	{
		if (this->value == other.value) if (this->name == other.name) return 2; else return 1;
		return 0;
	}
	int PropertyClass::Set(Property* prop)
	{
		if (prop->name == "")
		{
			status = false;
			return 0;
		}
		property.insert(std::pair<std::string, Property*>(prop->name, prop));

		status = true;
		return 1;
	}
	int PropertyClass::Set(std::string name, double val)
	{
		if (name == "")
		{
			status = false;
			return 0;
		}
		property.insert(std::pair<std::string, Property*>(name, new Property(val)));

		status = true;
		return 1;
	}
	int PropertyClass::Set(std::string name, std::string val)
	{
		if (name == "")
		{

			status = false;
			return 0;
		}
		property.insert(std::pair<std::string, Property*>(name,new  Property(val)));

		status = true;
		return 1;
	}
	int PropertyClass::Clear()
	{
		property.clear();

		status = true;
		return 1;
	}
	Property* PropertyClass::Get(std::string name)
	{
		auto it = property.find(name);
		if (it != property.end()) {

			status = true;
			return it->second;
		}

		status = false;
		return nullptr;
	}
	std::string PropertyClass::GetString(std::string name)
	{
		auto it = property.find(name);
		if (it != property.end())
		{
			status = true;
			return it->second->value;
		}
		status = false;
		return std::string();
	}
	double PropertyClass::GetDouble(std::string name)
	{

		auto it = property.find(name);
		if (it != property.end()) {

			status = true;
			return it->second->ToDouble();
		}

		status = false;
		return 0.0;
	}
}