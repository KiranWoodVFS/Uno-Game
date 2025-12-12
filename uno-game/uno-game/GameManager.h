#pragma once
#include "Player.h"
#include "Computer.h"

class GameManager
{
public:
	static GameManager* GetInstance();
	void StartGame();

	void PlayGame();

	void WinGame();
	void LoseGame();

private:
	static GameManager* _Instance;
	Player* _player;
	Computer* _computer;
	Deck* _deck;
};

