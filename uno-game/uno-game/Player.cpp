#include "Player.h"
#include "RenderText.h"
#include "Hand.h"

Player::Player(Deck* deck, RenderText* renderText)
{
	_deck = deck;
	_renderer = renderText;
	_hand = new Hand(_deck);
}

void Player::PlayerTurn()
{
	_renderer->PlayerTurnRender(false); // hasn't played, hasn't picked
	int input = InputAskCard();

	if (input == 0) // Picks up card
	{
		_hand->AddCardToHand();
	}
	else // Chooses card index to play card
	{
		if (_deck->CanPlayCard(_hand->GetCard(input - 1))) // Checks if card can be played
		{
			_hand->PlayCard(input - 1); 
		}
		else
		{
			PlayerTurn();
			return;
		}
	}

	_renderer->PlayerTurnRender(true);  // has played already
	WAIT_FOR_INPUT;
}

int Player::InputAskCard()
{
	int input;

	// Asks input until player types an int
	do
	{
		std::cin >> input;
		if (!std::cin.fail())
		{
			if (input <= _hand->GetCardAmount())
			{
				break;
			}
		}
		std::cin.clear(); \
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		BLUE_COLOUR_LOG(LOG_LN, "you failed >:(");
	} while (true);
	

	return input;
}
