#pragma once
#include "System.hpp"
#include "Core.hpp"
#include <vector>
#include "Types.hpp"
namespace Majestic
{
	class ViewPort
	{
	public:
		std::string m_name;
		Rectangle m_view;
	};
	class Graphics : public System
	{
	public:
		
		//Loading and handling methods
		Graphics();
		~Graphics();
		virtual int Init();
		virtual int Shutdown();
		virtual int Reload();
		void SetHWND(HWND);
		void InitGL();

		HDC GetHDC();
		HGLRC GetHGLRC();
		//Draw methods
		void Clear();
	protected:

		HWND _hwnd;
		HDC _hdc;
		HGLRC _hglrc;
		std::vector<ViewPort> _viewport;
		std::string _currentport;
		glColor4 _clearColor;
	};
}