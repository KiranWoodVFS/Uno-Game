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

// Chooses wild card
void Computer::ChooseWildColor()
{
	// Goes through card to check for colour
	for (Card* card : _hand->GetCards())
	{
		// Checks if card is not a wild card
		if (card->GetColor() != WILD)
		{
			// Sets wild card color
			_deck->SetWildColor(card->GetColor());

			return;
		}
	}
	
	//!!!!! CHANGE TO LET USER KNOW WHICH COLOUR COMPUTER PICKED
	BLUE_COLOUR_LOG(LOG_LN, BLUE);
	WAIT_FOR_INPUT;

	// If there is no avaliable color picks blue
	_deck->SetWildColor(BLUE);
}


