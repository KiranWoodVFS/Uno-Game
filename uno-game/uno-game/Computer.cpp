#include "Computer.h"

Computer::Computer(Deck* deck)
{
	_deck = deck;
	_hand = new Hand(deck);
}

void Computer::MoveAction(Color colorChosen)
{
	for (int i = 0; i < _hand->GetCardAmount(); i++)
	{
		if (_deck->CanPlayCard((_hand->GetCards()).at(i), colorChosen))
		{
			PlaceCard(i);
			return;
		}
	}

	_hand->AddCardToHand();
}

void Computer::PlaceCard(int cardIndex)
{
	if (_hand->GetCard(cardIndex)->GetColor() == WILD)
	{

	}
}
