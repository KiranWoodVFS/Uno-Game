#pragma once
#include "Entity.h"

class Computer : public Entity
{
public:

	Computer(Deck* deck);

	Card* MoveAction();

	void PickupCard();

private:

	// Functions to choose which card to put down
};

