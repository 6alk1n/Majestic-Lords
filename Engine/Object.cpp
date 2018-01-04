#include "Object.hpp"

namespace Majestic
{
	Object::Object()
	{
		pos = Vector(0);
		vel = Vector(0);
		size = Vector(0);
		texture = nullptr;
		uv = Rectangle(0);
	}
	Object::~Object()
	{

	}
	int Object::Draw(Graphics* graphics)
	{
		//Bind texture
		if (texture)
			glBindTexture(GL_TEXTURE_2D, texture->_textureID);

		glBegin(GL_QUADS);
		glTexCoord2d(uv.x, uv.y);
	//	glColor4f(color.r,color.g,color.b,color.a);
		glVertex2i((GLint)pos.x, (GLint)pos.y);

		glTexCoord2d(uv.w, uv.y);
	//	glColor4f(color.r, color.g, color.b, color.a);
		glVertex2i((GLint)pos.x+ (GLint)size.x, (GLint)pos.y);


		glTexCoord2d(uv.w, uv.h);
	//	glColor4f(color.r, color.g, color.b, color.a);
		glVertex2i((GLint)pos.x+ (GLint)size.x, (GLint)pos.y+ (GLint)size.y);

		glTexCoord2d(uv.x, uv.h);
	//	glColor4f(color.r, color.g, color.b, color.a);
		glVertex2i((GLint)pos.x, (GLint)pos.y+ (GLint)size.y);
		glEnd();

		//Unbind texture
		if (texture)
			glBindTexture(GL_TEXTURE_2D, NULL);
		return 1;
	}
	int Object::Update(double step)
	{
		pos += vel/step;
		return 1;
	}
}