// Starts game manager
#include "Utils.h"
#include "Computer.h"
#include "Player.h"

int main()
{
	Deck* deck = new Deck();

	Computer* computer = new Computer(deck);

	Card* currentCard = deck->GetCurrentCard();

	Player* player = new Player(deck);
	player->PlayerTurn();
}