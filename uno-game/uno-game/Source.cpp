
// Starts game manager
#include "Deck.h"

int main()
{
	Deck* deck = new Deck();

	Card* card = deck->DrawCard();
	Card* card1 = new Card(BLUE, "6");
	deck->PlayCard(card1);
	Card* card2 = new Card(RED, "1");
	
	WHITE_COLOUR_LOG(LOG_LN, deck->CanPlayCard(card2, RED));
}