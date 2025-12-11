#pragma once
#include "Entity.h"

class Computer : Entity
{
public:

	Computer(Deck* deck);

	void MoveAction();

private:

	// Functions to choose which card to put down
};

