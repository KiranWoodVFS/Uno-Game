#pragma once
#include "Hand.h"
#include "Card.h"
#include "RenderText.h"

class Entity
{
private:
	Card* playedCard;
	Hand _hand;
public:
	virtual void PerformTurn();
	const Hand& GetHand();
};

