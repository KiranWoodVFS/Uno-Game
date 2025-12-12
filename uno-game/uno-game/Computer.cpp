#include "Computer.h"

// Creates computer and makes deck
Computer::Computer(Deck* deck)
{
	_deck = deck;
	_hand = new Hand(deck);
}

// Computer does an action. Returns the card if placed down
Card* Computer::MoveAction()
{
	// Tries to put down first card possible
	for (int i = 0; i < _hand->GetCardAmount(); i++)
	{
		if (CheckCard(i))
		{
			Card* card = _hand->GetCard(i);
			// Plays down card
			_hand->PlayCard(i);
			return card;
		}
	}

	// Picks up Card
	PickupCard();
	return nullptr;
}

// Picks up a card
void Computer::PickupCard()
{
	_hand->AddCardToHand();
}
