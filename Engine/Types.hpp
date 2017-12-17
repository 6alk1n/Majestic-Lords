#pragma once
#include <string>
#include <sstream>
namespace Majestic
{
	double StrToDouble(std::string str)
	{
		std::stringstream geek(str);
		double x = 0;
		geek >> x;
		return x;
	}
}