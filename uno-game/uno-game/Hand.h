#pragma once
#include "Utils.h"
#include "Deck.h"


class Hand
{
public:

	// Constructor. Takes in the deck
	Hand(Deck* deck);

	// Actions for user
	void AddCardToHand();
	void PlayCard(int cardIndex);

	// Getters
	vector<Card*> GetCards();
	Card* GetCard(int cardIndex);
	int GetCardAmount();

private:

	Deck* _deck; // Instance of the deck

	int _cardAmount; // Amount of cards in hand
	vector<Card*> _cards; // Vector of cards
};

