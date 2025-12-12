#pragma once

class Card;

class RenderText
{
public:
	RenderText();

	void ShowDiscardTop(Card* topCard);
	void ShowPlayerHand();
	void ShowOpponentHand();
	void PlayerTurnRender(bool isSecondPhase);
	void OpponentTurnRender(bool isSecondPhase);
	void ShowResult(bool hasWon);
};

