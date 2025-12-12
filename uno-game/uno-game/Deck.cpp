#include "Deck.h"
#include "Card.h"

void checkCards(vector<Card*> cards)
{
    for (Card* card : cards)
    {
        WHITE_COLOUR_LOG(LOG, card->GetColor() << " " << card->GetSymbol() << " || ");
    }
    LOG_EMPTY_LN();
    BLUE_COLOUR_LOG(LOG_LN, "======================");
}

// Creates and shuffles the Deck
Deck::Deck()
{
    _wildColor = WILD;

    CreateDeck();
    ShuffleDeck();
    
    _discardPile.push_back(_currentDeck.back());
    _currentDeck.pop_back();
}

// Creates each card to add to deck
void Deck::CreateDeck()
{
    // Creates 2 cards for 1-9 of each color
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            _currentDeck.push_back(new Card(static_cast<Color>(j + 90), to_string(i)));
            _currentDeck.push_back(new Card(static_cast<Color>(j + 90), to_string(i)));
        }
    }

    // Creates 0, skips and +2 for each color
    for (int j = 1; j < 5; j++)
    {
        _currentDeck.push_back(new Card(static_cast<Color>(j + 90), "0")); // Only one 0

        // Two +2 and skip
        for (int i = 0; i < 2; i++)
        {
            _currentDeck.push_back(new Card(static_cast<Color>(j + 90), "s"));
            _currentDeck.push_back(new Card(static_cast<Color>(j + 90), "+2"));
        }
    }
    
    // Adds 4 wildcards
    for (int i = 1; i < 5; i++)
    {
        _currentDeck.push_back(new Card(static_cast<Color>(WILD), "W"));
    }
}

// Shuffles the current deck
void Deck::ShuffleDeck()
{
    // Sets a random generator to use
    std::random_device rd;
    std::mt19937 g(rd());

    shuffle(_currentDeck.begin(), _currentDeck.end(), g); // Shuffles vector
}

// Moves discard pile to current deck and then shuffles
void Deck::ReShuffleDeck()
{
    // Adds to current deck
    _currentDeck = _discardPile;
    _currentDeck.pop_back(); // Removes the final card

    // Removes discard cards minus the back one
    _discardPile.erase(_discardPile.begin(), _discardPile.end() - 1);

    ShuffleDeck();

}

// Returns the card from the back of the deck
Card* Deck::DrawCard()
{
    Card* card = _currentDeck.back();
    _currentDeck.pop_back(); // Removes card

    return card;
}

// Puts the card in the discard pile
void Deck::PlayCard(Card* card)
{
    _discardPile.push_back(card);
}

// Returns if the card can be played
bool Deck::CanPlayCard(Card* card)
{
    Card* currentCard = GetCurrentCard();
    bool result = false;

    // Checks if color or symbol is the same. Or if the card is a wild card
    if (card->GetColor() == currentCard->GetColor() || card->GetSymbol() == currentCard->GetSymbol())
    {
        result = true;
    }
    // Checks if current card is a wildcard and if so which color was chosen
    else if (currentCard->GetColor() == WILD && card->GetColor() == _wildColor)
    {
        return true;
    }

    return result;
}

// Gets the last card placed in discard pile
Card* Deck::GetCurrentCard()
{
    return _discardPile.back();
}

// Gets the amount of cards in the current deck
int Deck::GetCardsLeftInDeck()
{
    return _currentDeck.size();
}

