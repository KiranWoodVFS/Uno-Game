#include "Computer.h"
#include "RenderText.h"
#include "Hand.h"
#include "Card.h"

// Creates computer and makes deck
Computer::Computer(Deck* deck, RenderText* renderer)
{
	_deck = deck;
	_hand = new Hand(deck);
	_renderer = renderer;
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
