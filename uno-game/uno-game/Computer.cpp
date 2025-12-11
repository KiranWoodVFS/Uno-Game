#include "Computer.h"

Computer::Computer(Deck* deck)
{
	_deck = deck;
	_hand = new Hand(deck);
}

void Computer::MoveAction()
{
	for (Card* card : _hand->GetCards())
	{
		WHITE_COLOUR_LOG(LOG, (card->GetColor()) << " || " << card->GetSymbol() << " || ");

		WHITE_COLOUR_LOG(LOG_LN, _deck->CanPlayCard(card, WILD));
	}
}
