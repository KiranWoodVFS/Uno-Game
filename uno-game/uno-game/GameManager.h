#pragma once
#include "Player.h"

class Player;
class Computer;
class Deck;
class RenderText;

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
	RenderText* _renderer;
};

