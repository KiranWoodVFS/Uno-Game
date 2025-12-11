#include "Hand.h"

Hand::Hand()
{
    for (int i = 0; i < 7; i++)
    {
    }
    
    _cardAmount = 7;
}

void Hand::AddCardToHand()
{
}

void Hand::PlayCard()
{
}

vector<Card*> Hand::GetCards()
{
    return _cards;
}

vector<Card*> Hand::GetCardAmount()
{
    return vector<Card*>();
}
