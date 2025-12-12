#pragma once
#include "Player.h"
#include "Card.h"

class RenderText
{
public:
	static RenderText* GetInstance();

	void ShowDiscardTop(Card* topCard);
	void ShowPlayerHand();
	void ShowOpponentHand();
	void PlayerTurnRender(bool isSecondPhase);
	void OpponentTurnRender(bool isSecondPhase);
	void ShowResult(bool hasWon);
private:
	static RenderText* sInstance;
};

