#include "Entity.h"
#include "Hand.h"
#include "Deck.h"

bool Entity::CheckWin()
{
	if (_hand->GetCardAmount() <= 0)
	{
		return true;
	}

	return false;
}

bool Entity::CheckCard(int cardIndex)
{
	if (_deck->CanPlayCard((_hand->GetCards()).at(cardIndex)))
	{
		return true;
	}
	return false;
}

vector<Card*> Entity::GetCardsInHand()
{
	
	return vector<Card*>(_hand->GetCards());
}

