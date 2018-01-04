#pragma once
#include "Texture.hpp"
#include <map>
#include <string>
namespace Majestic {
	class TextureManager
	{
	public:
		TextureManager();
		~TextureManager();
		Texture* GetTexture(std::string);
		void AddTexture(std::string, Texture*);
	protected:
		std::map<std::string, Texture*> textures;
	};
}