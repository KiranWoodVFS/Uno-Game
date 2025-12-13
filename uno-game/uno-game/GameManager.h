#pragma once
#include "Player.h"

class Player;
class Computer;
class Deck;
class RenderText;

class GameManager
{
public:

	// Gets game instance
	static GameManager* GetInstance();

	// Game states
	void StartGame();
	void PlayGame();

private:

	static GameManager* _Instance;

	Player* _player;
	Computer* _computer;
	Deck* _deck;
	RenderText* _renderer;
};

