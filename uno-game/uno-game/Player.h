#pragma once
#include "Entity.h"
#include "RenderText.h"

class Player : Entity
{
public:

	Player(Deck* deck);

	void PlayerTurn();

	int AskActionInput();

private:

	// Inheritants from entity
	// Inputs 
};

