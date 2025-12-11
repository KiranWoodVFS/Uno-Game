#include "Hand.h"

Hand::Hand(Deck* deck)
{
    _deck = deck;
    for (int i = 0; i < 7; i++)
    {
        _cards.push_back(_deck->DrawCard());
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
