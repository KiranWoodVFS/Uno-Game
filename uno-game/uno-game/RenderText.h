#pragma once
#include "Player.h"
#include "Card.h"

class RenderText
{
	// All the LOG_LN's that the text will see
public:
	void ShowDeckTop(bool mode);
	void ShowPlayerHand();
	void ShowOpponentHand();
	void PlayerTurnRender();
	void OpponentTurnRender();
};

