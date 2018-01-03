#include "Graphics.hpp"

using namespace Majestic;

Graphics::Graphics()
	:System()
{
	_name = "Graphics System";
	
}
Graphics::~Graphics()
{

}
int Graphics::Init()
{
	//Create OpenGL Context
	_hdc = GetDC(_hwnd);

	/* there is no guarantee that the contents of the stack that become
	the pfd are zeroed, therefore _make sure_ to clear these bits. */
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;

	int pf = ChoosePixelFormat(_hdc, &pfd);
	if (pf == 0) {
			return 0;
	}

	if (SetPixelFormat(_hdc, pf, &pfd) == FALSE) {
			return 0;
	}

	DescribePixelFormat(_hdc, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	ReleaseDC( _hwnd, _hdc);

	_hdc = GetDC(_hwnd);
	_hglrc = wglCreateContext(_hdc);
	wglMakeCurrent(_hdc, _hglrc);

	InitGL();

	if (glewInit())
		return 0;
	return 1;
}

HDC Graphics::GetHDC()
{
	return _hdc;
}
HGLRC Graphics::GetHGLRC()
{
	return _hglrc;
}
int Graphics::Shutdown()
{

	return 1;
}
int Graphics::Reload()
{

	return 1;
}
void Graphics::SetHWND(HWND hwnd)
{
	_hwnd = hwnd;
}
void Graphics::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}		
void Graphics::InitGL()
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(0.0f, windowWidth, windowHeight, 0.0f, 0.0f, 1.0f);

	//Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

	//Check for error
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		//printf("Error initializing OpenGL! %s\n", gluErrorString(error));
	}
}