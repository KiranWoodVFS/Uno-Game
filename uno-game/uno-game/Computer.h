#pragma once
#include "Entity.h"

class Computer : Entity
{
public:

	Computer(Deck* deck);

	void MoveAction(Color color);

	void PlaceCard(int cardIndex);

private:

	// Functions to choose which card to put down
};

