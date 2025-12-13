// Starts game manager
#include "GameManager.h"
#include <windows.h>

int main()
{
	// Creates and starts game
	SetConsoleOutputCP(CP_UTF8);
	GameManager* gameManager = new GameManager();
	gameManager->StartGame();

}