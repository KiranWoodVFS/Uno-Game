#include "Player.h"
#include "Hand.h"
#include "Card.h"

// Constructor
Player::Player(Deck* deck, RenderText* renderText)
{
	_deck = deck;
	_renderer = renderText;
	_hand = new Hand(_deck);
}
 
Card* Player::PlayerTurn()
{
	int input = Input(_hand->GetCardAmount());

	if (input == 0) // Picks up card
	{
		PickupCard();
		return nullptr;
	}
	else // Chooses card index to play card
	{
		if (_deck->CanPlayCard(_hand->GetCard(input - 1))) // Card can be played
		{
			Card* card = _hand->GetCard(input - 1);
			_hand->PlayCard(input - 1);
			return card;
		}
		else // Player needs to redo turn. Card cannot be played
		{
			RED_COLOUR_LOG(LOG_LN, "Can't play that!");
			WHITE_COLOUR_LOG(LOG, "");
			PlayerTurn();
			return nullptr;
		}
	}
}

// Adds a card to the player's deck
void Player::PickupCard()
{
	_hand->AddCardToHand();
}

// Lets player pick a wild card
void Player::ChooseWildColor()
{
	WHITE_COLOUR_LOG(LOG, "WILDCARD PLAYED: Select a color to switch:\nType '0' for ");
	RED_COLOUR_LOG(LOG, "RED\n");
	WHITE_COLOUR_LOG(LOG, "Type '1' for ");
	GREEN_COLOUR_LOG(LOG, "GREEN\n");
	WHITE_COLOUR_LOG(LOG, "Type '2' for ");
	YELLOW_COLOUR_LOG(LOG, "YELLOW\n");
	WHITE_COLOUR_LOG(LOG, "Type '3' for ");
	BLUE_COLOUR_LOG(LOG, "BLUE\n");
	WHITE_COLOUR_LOG(LOG, "");

	int color = Input(3);

	_deck->SetWildColor(static_cast<Color>(color + 91));
}

// Asks for player input
int Player::Input(int maxInputRange)
{
	int input;

	// Asks input until player types an int
	do
	{
		std::cin >> input;
		if (!std::cin.fail())
		{
			if (input <= maxInputRange && input >= 0) // Within maxInputRange
			{
				break;
			}
		}
		std::cin.clear(); \
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Wrong Input
		RED_COLOUR_LOG(LOG_LN, "Invalid card!");
		WHITE_COLOUR_LOG(LOG, "");
	} while (true);
	
	return input;
}
