#include "Entity.h"

bool Entity::CheckWin()
{
	if (_hand->GetCardAmount() <= 0)
	{
		return true;
	}

	return false;
}
