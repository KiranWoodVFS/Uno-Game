#pragma once
#include "Entity.h"

class Deck;
class RenderText;
class Card;

class Player : public Entity
{
public:

	Player(Deck* deck, RenderText* renderText);

	Card* PlayerTurn();

	// Special Actions
	void PickupCard();
	void ChooseWildColor();

	// Asks for input from player
	int Input(int maxInput);

private:

	RenderText* _renderer;
};

