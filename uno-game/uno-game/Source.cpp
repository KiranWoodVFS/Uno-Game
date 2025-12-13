// Starts game manager
#include "GameManager.h"
#include <windows.h>

int main()
{
	// Changes console output
	SetConsoleOutputCP(CP_UTF8);

	// Creates and starts game
	GameManager* gameManager = new GameManager();
	gameManager->StartGame();

}