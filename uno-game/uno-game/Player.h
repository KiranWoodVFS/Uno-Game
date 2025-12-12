#pragma once
#include "Entity.h"

class Deck;
class RenderText;

class Player : public Entity
{
public:

	Player(Deck* deck, RenderText* renderText);

	void PlayerTurn();

	int InputAskCard();

private:

	RenderText* _renderer;
	// Inheritants from entity
	// Inputs 
};

