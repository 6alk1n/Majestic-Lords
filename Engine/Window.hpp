#pragma once
#include "System.hpp"
#include "Core.hpp"
#include "Input.hpp"
LRESULT WINAPI WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
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
		const HINSTANCE GetInstance();
		const HWND GetHWND();
	protected:
		virtual int InitWindow();
		HINSTANCE _hInstance;
		Input* _input; //shared with application input
		friend class Application;
		HWND _hwnd;
	};
}