#pragma once
#include "Core.hpp"
#include <string>
#include <vector>
namespace Majestic
{
	extern int decodePNG(std::vector<unsigned char>& out_image, unsigned long& image_width, unsigned long& image_height, const unsigned char* in_png, size_t in_size, bool convert_to_rgba32 = true);

	class Utility
	{
	public:
		static int readToBuffer(std::string, std::vector<unsigned char>&);
		static bool readToBuffer(std::string filePath, std::string& buffer);
		static bool readToBuffer(std::string filePath, std::vector<std::string>& buffer);

		static GLuint CreateTexture(unsigned char* pixels, unsigned int w, unsigned int h);
		static unsigned int LoadPNG(std::string);
		
		static unsigned char* LoadBMP(std::string, unsigned int& w, unsigned int& h);
		static unsigned int LoadTextureIL(std::string);

	

	protected:
	};
}