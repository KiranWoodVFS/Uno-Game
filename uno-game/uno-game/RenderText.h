#pragma once
#include "Player.h"
#include "Card.h"

class RenderText
{
	// All the LOG_LN's that the text will see
public:
	void PrintCards(Player& player);
	void ShowPlayerHand();
	void ShowOpponentHand();
};

