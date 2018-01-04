#include "TextureManager.hpp"
#include "Utility.hpp"
using namespace Majestic;
TextureManager::TextureManager(){}
TextureManager::~TextureManager(){}
Texture* TextureManager::GetTexture(std::string texturePath)
{
	auto mit = textures.find(texturePath);

	//check if its not in the map
	if (mit == textures.end()) {
		//Load the texture
		GLuint newTexture = Utility::LoadPNG(texturePath);

		Texture* tex = new Texture;
		tex->_textureID = newTexture;
		//Insert it into the map
		textures.insert(make_pair(texturePath, tex));

		return tex;
	}
	return mit->second;
}
void TextureManager::AddTexture(std::string texturePath, Texture* tex)
{
	auto mit = textures.find(texturePath);

	//check if its not in the map
	if (mit == textures.end()) {
		//Insert it into the map
		textures.insert(make_pair(texturePath, tex));
	}
}