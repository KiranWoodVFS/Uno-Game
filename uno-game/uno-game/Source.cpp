// Starts game manager
#include "Utils.h"
#include "RenderText.h"
#include "windows.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	RenderText renderer;
	renderer.PrintCards();
}