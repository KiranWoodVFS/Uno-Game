#pragma once
#include "Utils.h"
#include "Card.h"

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

	// Checks if card can be played
	bool CanPlayCard(Card* card);

	// Getters
	Card* GetCurrentCard();
	int GetCardsLeftInDeck();

	// Sets the wildcard color
	void SetWildColor(Color color);

private:

	vector<Card*> _currentDeck; // Cards player can pick from
	vector<Card*> _discardPile; // Cards already played
	Color _wildColor = WILD;
};

