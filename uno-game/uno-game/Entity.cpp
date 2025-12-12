#include "Entity.h"

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
