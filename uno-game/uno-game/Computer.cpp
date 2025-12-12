#include "Computer.h"

Computer::Computer(Deck* deck)
{
	_deck = deck;
	_hand = new Hand(deck);
}

void Computer::MoveAction(Color colorChosen)
{
	// Tries to put down first card possible
	for (int i = 0; i < _hand->GetCardAmount(); i++)
	{
		if (CheckCard(i, colorChosen))
		{
			PlaceCard(i);
			return;
		}
	}

	// Takes Card
	_hand->AddCardToHand();
}

void Computer::PlaceCard(int cardIndex)
{
	if (_hand->GetCard(cardIndex)->GetColor() == WILD)
	{

	}
}
