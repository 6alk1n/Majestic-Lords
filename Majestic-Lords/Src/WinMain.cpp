#include <Engine/Core.hpp>

int CALLBACK WinMain(
	HINSTANCE   hInstance,
	HINSTANCE   hPrevInstance,
	LPSTR       lpCmdLine,
	int         nCmdShow
)
{
	if (Majestic::InitEngine() !=1 )
	return -1;

	if (Majestic::KillEngine() != 1)
		return -1;

	return 1;
}