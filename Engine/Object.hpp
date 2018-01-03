#pragma once
#include "Types.hpp"
#include "Graphics.hpp"
namespace Majestic {
	class Object
	{
	public:
		Object();
		~Object();
		virtual int Draw(Graphics*);
		virtual int Update(double);

		Vector pos;
		Vector vel;
		Vector size;
		glColor4 color;
	protected:

	};
}