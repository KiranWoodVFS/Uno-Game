#pragma once
#include "Utils.h"

class Card;
class Deck;

class RenderText
{
public:
	RenderText();

	void WelcomeRender();
	void ShowDiscardTop(Card* topCard);
	void ShowPlayerHand(vector<Card*> playerHand);
	void ShowOpponentHand(vector<Card*> computerHand);
	void PlayerTurnRender(bool secondPhase, vector<Card*> playerHand, vector<Card*> computerHand, Deck* deck);
	void OpponentTurnRender(bool secondPhase, vector<Card*> computerHand, Deck* deck);
	void ShowResult(bool hasWon);

};

