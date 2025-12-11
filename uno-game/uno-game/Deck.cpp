#include "Deck.h"

// Creates the Deck
Deck::Deck()
{
    CreateDeck();
}

// Creates each card to add to deck
void Deck::CreateDeck()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            _currentDeck.push_back(new Card(static_cast<Color>(j), "3"));
        }
    }
}

void Deck::ShuffleDeck()
{

}

void Deck::ReShuffleDeck()
{
}

Card* Deck::DrawCard()
{
    return new Card(RED, "3");
}

void Deck::PlaceCard(Card* card)
{
}

Card* Deck::GetCurrentCard()
{
    return new Card(RED, "4");
}
