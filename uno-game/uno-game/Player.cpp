#include "Player.h"

Player::Player(Deck* deck)
{
}

void Player::PlayerTurn()
{
	int input = AskActionInput();

	

}

int Player::AskActionInput()
{
	int input;

	// Asks input until player types an int
	do
	{
		std::cin >> input;
		if (!std::cin.fail())
		{
			break;
		}
		std::cin.clear(); \
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		BLUE_COLOUR_LOG(LOG_LN, "you failed >:(");
	} while (true);
	

	return input;
}
