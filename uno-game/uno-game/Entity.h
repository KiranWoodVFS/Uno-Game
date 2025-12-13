#pragma once
#include "Utils.h"

class Hand;
class Deck;
class Card;

class Entity
{
public: 

	// Checks if the user has won
	virtual bool CheckWin();

	// Checks if the card can be played
	virtual bool CheckCard(int cardIndex);

	// Gets the amount of cards in the hand
	virtual vector<Card*> GetCardsInHand();

protected:

	Hand* _hand; // Hand of user
	Deck* _deck; // The current deck
};

