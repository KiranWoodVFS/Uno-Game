#pragma once
#include "Card.h"
#include "Utils.h"

class Deck
{
public:
	
	Deck();

	void CreateDeck();

	// Shuffles deck
	void ShuffleDeck();
	void ReShuffleDeck();

	// User actions
	Card* DrawCard();
	void PlayCard(Card* card);

	// Getters
	Card* GetCurrentCard();
	int GetCardsLeftInDeck();

	// Checks if card can be played
	bool CanPlayCard(Card* card);

private:

	vector<Card*> _currentDeck; // Cards player can pick from
	vector<Card*> _discardPile; // Cards already played
	Color wildColor = WILD;
};

