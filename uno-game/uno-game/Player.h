#pragma once
#include "Entity.h"
#include "RenderText.h"

class Player : public Entity
{
public:

	Player(Deck* deck);

	void PlayerTurn();

	int InputAskCard();

private:

	// Inheritants from entity
	// Inputs 
};

