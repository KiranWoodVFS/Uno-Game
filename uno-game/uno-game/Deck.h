#pragma once
#include "Card.h"

class Deck
{
public:

	Deck();

	void CreateDeck();
	void ShuffleDeck();

	void ReShuffleDeck();

	Card getTopOfDeck();
	

private:
	
	vector<Card> _currentDeck;
	vector<Card> _discardPile;
};

