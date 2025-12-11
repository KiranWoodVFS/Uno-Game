#pragma once
#include "Hand.h"
#include "Card.h"

class Entity
{
private:
	Hand _hand;
	Card* playedCard;
public:
	virtual void PerformTurn();
};

