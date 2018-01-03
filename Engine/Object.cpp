#include "Object.hpp"

namespace Majestic
{
	Object::Object()
	{
		pos = Vector(0);
		vel = Vector(0);
		size = Vector(0);
	}
	Object::~Object()
	{

	}
	int Object::Draw(Graphics* graphics)
	{
		//Draw rect
		glBegin(GL_QUADS);
		glColor4f(color.r,color.g,color.b,color.a);
		glVertex2i(pos.x, pos.y);
		glColor4f(color.r, color.g, color.b, color.a);
		glVertex2i(pos.x+size.x, pos.y);
		glColor4f(color.r, color.g, color.b, color.a);
		glVertex2i(pos.x+size.x, pos.y+size.y);
		glColor4f(color.r, color.g, color.b, color.a);
		glVertex2i(pos.x, pos.y+size.y);
		glEnd();
		return 1;
	}
	int Object::Update(double step)
	{
		pos += vel/step;
		return 1;
	}
}