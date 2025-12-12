#pragma once
#include "Hand.h"

class Entity
{
public: 

	virtual bool CheckWin();

	virtual bool CheckCard(int cardIndex);

protected:

	Hand* _hand;
	Deck* _deck;

};

