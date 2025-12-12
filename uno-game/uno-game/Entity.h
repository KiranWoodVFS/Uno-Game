#pragma once
#include "Hand.h"

class Entity
{
public: 

	virtual bool CheckWin();

protected:

	Hand* _hand;
	Deck* _deck;

};

