#pragma once
#include "System.hpp"
#include <SDL\SDL.h>
namespace Majestic
{
	static const int WindowDefaultWidth = 1024;
	static const std::string WindowDefaultTitle = "MajesticTitle";
	static const int WindowDefaultHeight = 768;
	class Window : public System
	{
	public:
		Window();
		~Window();	
		virtual int Init() override;
		virtual int Shutdown() override;
		virtual int Reload() override;
		int ResizeScreen(unsigned int w,unsigned int h);
		int RenameWindow(std::string name);
		int SetScreenPos(unsigned int x,unsigned int y);
		int SetVsync(bool);


		SDL_Window* _window;
		SDL_Surface* _surface;
	protected:
	};
}