#pragma once
#include "Card.h"

class Deck
{
public:

	Deck();

	void CreateDeck();
	void ShuffleDeck();

	void ReShuffleDeck();

	Card* DrawCard();
	void PlayCard(Card* card);
	Card* GetCurrentCard();

	bool CanPlayCard(Card* card, Color color);

private:

	vector<Card*> _currentDeck; // Cards player can pick from
	vector<Card*> _discardPile; // Cards already played
};

