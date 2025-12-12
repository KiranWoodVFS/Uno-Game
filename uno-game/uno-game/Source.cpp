// Starts game manager
#include "Utils.h"
#include "Computer.h"

int main()
{
	Deck* deck = new Deck();

	Computer* computer = new Computer(deck);

	Card* currentCard = deck->GetCurrentCard();
	WHITE_COLOUR_LOG(LOG_LN, currentCard->GetColor() << "  " << currentCard->GetSymbol());

}