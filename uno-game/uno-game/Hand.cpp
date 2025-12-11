#pragma once
#include "Hand.h"

Hand::Hand(Deck* deck) : _deck(deck)
{
    for (int i = 0; i < 7; i++)
    {
        AddCardToHand();
    }
}

void Hand::AddCardToHand()
{
    _cards.push_back(_deck->DrawCard());
    _cardAmount++;
}

void Hand::PlayCard(int cardIndex)
{
    _deck->PlayCard(_cards.at(cardIndex));
}

vector<Card*> Hand::GetCards()
{
    return _cards;
}

Card* Hand::GetCard(int cardIndex)
{
    return _cards.at(cardIndex);
}

int Hand::GetCardAmount()
{
    return _cardAmount;
}
