#pragma once
#include "Entity.h"

class RenderText;
class Deck;
class Card;

class Computer : public Entity
{
public:

	Computer(Deck* deck, RenderText* renderer);

	// Computer moves
	Card* MoveAction();

	// Special Actions
	void PickupCard();
	void ChooseWildColor();

private:

	RenderText* _renderer;
	// Functions to choose which card to put down
};

