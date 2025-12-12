#pragma once
#include "Player.h"
#include "Card.h"

class RenderText
{
	// All the LOG_LN's that the text will see
public:
	void ShowDiscardTop(Card* topCard);
	void ShowPlayerHand();
	void ShowOpponentHand();
	void PlayerTurnRender(bool isSecondPhase, bool picked);
	void OpponentTurnRender(bool isSecondPhase);
	void ShowResult(bool hasWon);
};

