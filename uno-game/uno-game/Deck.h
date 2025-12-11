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
	void PlaceCard(Card* card);
	Card* GetCurrentCard();

private:

	vector<Card*> _currentDeck; // Cards player can pick from
	vector<Card*> _discardPile; // Cards already played
};

