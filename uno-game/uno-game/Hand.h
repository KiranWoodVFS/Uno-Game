#pragma once
#include "Deck.h"

class Hand
{
public:
	Hand(Deck* deck);

	void AddCardToHand();
	void PlayCard();

	vector<Card*> GetCards();
	vector<Card*> GetCardAmount();

private:

	int _cardAmount;
	vector<Card*> _cards;
	Deck* _deck;
};

