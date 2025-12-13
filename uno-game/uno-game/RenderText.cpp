#include "RenderText.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"


RenderText::RenderText()
{
}

void RenderText::WelcomeRender()
{
	LOG_EMPTY_LN();
	GREEN_COLOUR_LOG(LOG, "W");
	RED_COLOUR_LOG(LOG, "E");
	BLUE_COLOUR_LOG(LOG, "L");
	YELLOW_COLOUR_LOG(LOG, "C");
	GREEN_COLOUR_LOG(LOG, "O");
	RED_COLOUR_LOG(LOG, "M");
	BLUE_COLOUR_LOG(LOG, "E");
	LOG_SPACE();
	YELLOW_COLOUR_LOG(LOG, "T");
	GREEN_COLOUR_LOG(LOG, "O");
	LOG_SPACE();
	RED_COLOUR_LOG(LOG, "D");
	BLUE_COLOUR_LOG(LOG, "I");
	YELLOW_COLOUR_LOG(LOG, "G");
	GREEN_COLOUR_LOG(LOG, "I");
	RED_COLOUR_LOG(LOG, "T");
	BLUE_COLOUR_LOG(LOG, "A");
	YELLOW_COLOUR_LOG(LOG, "L");
	LOG_SPACE();
	WHITE_COLOUR_LOG(LOG, "==");
	WHITE_COLOUR_LOG(LOG, "U");
	WHITE_COLOUR_LOG(LOG, "N");
	WHITE_COLOUR_LOG(LOG, "O");
	WHITE_COLOUR_LOG(LOG, "==");
	LOG_EMPTY_LN();
	WHITE_COLOUR_LOG(LOG_LN, "By Kiran Wood and Tobias Arrieta");
	LOG_EMPTY_LN();
	WHITE_COLOUR_LOG(LOG_LN, "Are you ready?");
	GRAY_COLOUR_LOG(LOG_LN, "[Press any key]");
}

void RenderText::ShowPlayerHand(vector<Card*> playerHand)
{
	vector<Card*> cardsToPrint = playerHand;
	
	int cardWidth = 5;
	int cardHeight = 3;

	// ---- RENDERING: FIRST LINE ------------------------------------
	for (Card* card : cardsToPrint)
	{
		// Prints top corner
		COLOR_LOG(static_cast<int>(card->GetColor()), LOG, u8"┌");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(card->GetColor()), LOG, u8"┐");

		LOG_SPACE(); // Space for the next card
	}
	LOG_EMPTY_LN(); // Go to next line of rendering

	// ---- RENDERING: MIDDLE LINES ------------------------------------
	for (int i = 0; i < cardHeight; i++)
	{
		for (Card* card : cardsToPrint)
		{
			bool extendedSymbolFlag = false;

			// Prints all of the card interior
			COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "|");
			if (i == cardHeight / 2)
			{
				for (int j = 0; j < cardWidth; j++)
				{
					if (j == cardWidth / 2)
					{
						COLOR_LOG(static_cast<int>(card->GetColor()), LOG, card->GetSymbol());
					}
					else
					{
						if (card->GetSymbol() == "+2")
						{
							if (!extendedSymbolFlag)
							{
								extendedSymbolFlag = true;
							}
							else
							{
								LOG_SPACE();
							}
						}
						else
						{
							LOG_SPACE();
						}
					}
				}
			}
			else
			{
				for (int j = 0; j < cardWidth; j++)
				{
					LOG_SPACE();
				}
			}
			COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "|");

			LOG_SPACE(); // Space for the next card
		}

		LOG_EMPTY_LN(); // Go to next line of rendering
	}

	// ---- RENDERING: LAST LINE ------------------------------------
	for (Card* card : cardsToPrint)
	{
		// Prints bottom corner
		COLOR_LOG(static_cast<int>(card->GetColor()), LOG, u8"└");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(card->GetColor()), LOG, u8"┘");

		LOG_SPACE(); // Space for the next card
	}

	LOG_EMPTY_LN();
	int counter = 0;

	// ---- RENDERING: CARDS INDEXES ------------------------------------
	for (Card* card : cardsToPrint)
	{
		bool reducedSpaceFlag = false;

		// Prints all of the card interior
		LOG_SPACE();
		for (int j = 0; j < cardWidth; j++)
		{
			if (j == cardWidth / 2)
			{
				counter++;
				COLOR_LOG(static_cast<int>(97), LOG, counter);
			}
			else
			{
				if (counter > 9)
				{
					if (!reducedSpaceFlag)
					{
						reducedSpaceFlag = true;
					}
					else
					{
						LOG_SPACE();
					}
				}
				else
				{
					LOG_SPACE();
				}
			}
		}
		LOG_SPACE();
		LOG_SPACE(); // Space for the next card
	}


	// Card render finished at this point
}

void RenderText::ShowOpponentHand(vector<Card*> computerHand)
{
	vector<Card*> cardsToPrint = computerHand;

	int cardWidth = 5;
	int cardHeight = 3;

	// ---- RENDERING: FIRST LINE ------------------------------------
	for (Card* card : cardsToPrint)
	{
		// Prints top corner
		COLOR_LOG(static_cast<int>(37), LOG, u8"┌");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(37), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(37), LOG, u8"┐");

		LOG_SPACE(); // Space for the next card
	}
	LOG_EMPTY_LN(); // Go to next line of rendering

	// ---- RENDERING: MIDDLE LINES ------------------------------------
	for (int i = 0; i < cardHeight; i++)
	{
		for (Card* card : cardsToPrint)
		{
			// Prints all of the card interior
			COLOR_LOG(static_cast<int>(37), LOG, "|");
			for (int j = 0; j < cardWidth; j++)
			{
				COLOR_LOG(static_cast<int>(37), LOG, "-");
			}
			COLOR_LOG(static_cast<int>(37), LOG, "|");

			LOG_SPACE(); // Space for the next card
		}

		LOG_EMPTY_LN(); // Go to next line of rendering
	}

	// ---- RENDERING: LAST LINE ------------------------------------
	for (Card* card : cardsToPrint)
	{
		// Prints bottom corner
		COLOR_LOG(static_cast<int>(37), LOG, u8"└");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(37), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(37), LOG, u8"┘");

		LOG_SPACE(); // Space for the next card
	}
	LOG_EMPTY_LN();
}

void RenderText::ShowDiscardTop(Card* topCard)
{
	int cardWidth = 5;
	int cardHeight = 3;
	
	LOG_EMPTY_LN();
	// Prints top corner
	COLOR_LOG(static_cast<int>(topCard->GetColor()), LOG, u8"┌");
	for (int i = 0; i < cardWidth; i++)
	{
		COLOR_LOG(static_cast<int>(topCard->GetColor()), LOG, "-");
	}
	COLOR_LOG(static_cast<int>(topCard->GetColor()), LOG, u8"┐");
	LOG_SPACE();
	COLOR_LOG(static_cast<int>(37), LOG, u8"┌");
	for (int i = 0; i < cardWidth; i++)
	{
		COLOR_LOG(static_cast<int>(37), LOG, "-");
	}
	COLOR_LOG(static_cast<int>(37), LOG, u8"┐");


	LOG_EMPTY_LN(); // Go to next line of rendering

	for (int i = 0; i < cardHeight; i++)
	{
		bool extendedSymbolFlag = false;

		// Prints all of the card interior
		COLOR_LOG(static_cast<int>(topCard->GetColor()), LOG, "|");
		if (i == cardHeight / 2)
		{
			for (int j = 0; j < cardWidth; j++)
			{
				if (j == cardWidth / 2)
				{
					COLOR_LOG(static_cast<int>(topCard->GetColor()), LOG, topCard->GetSymbol());
				}
				else
				{
					if (topCard->GetSymbol() == "+2")
					{
						if (!extendedSymbolFlag)
						{
							extendedSymbolFlag = true;
						}
						else
						{
							LOG_SPACE();
						}
					}
					else
					{
						LOG_SPACE();
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < cardWidth; j++)
			{
				LOG_SPACE();
			}
		}
		COLOR_LOG(static_cast<int>(topCard->GetColor()), LOG, "|");

		LOG_SPACE();

		COLOR_LOG(static_cast<int>(37), LOG, "|");
		for (int j = 0; j < cardWidth; j++)
		{
			COLOR_LOG(static_cast<int>(37), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(37), LOG, "|");
		LOG_EMPTY_LN();
	}

	// Prints bottom corner
	COLOR_LOG(static_cast<int>(topCard->GetColor()), LOG, u8"└");
	for (int i = 0; i < cardWidth; i++)
	{
		COLOR_LOG(static_cast<int>(topCard->GetColor()), LOG, "-");
	}
	COLOR_LOG(static_cast<int>(topCard->GetColor()), LOG, u8"┘");

	LOG_SPACE();

	COLOR_LOG(static_cast<int>(37), LOG, u8"└");
	for (int i = 0; i < cardWidth; i++)
	{
		COLOR_LOG(static_cast<int>(37), LOG, "-");
	}
	COLOR_LOG(static_cast<int>(37), LOG, u8"┘");

	LOG_EMPTY_LN();

	for (int j = 0; j < cardWidth; j++)
	{
		if (j == cardWidth / 2)
		{
			COLOR_LOG(static_cast<int>(97), LOG, "PILE");
		}
		else
		{
			LOG_SPACE();
		}
	}
	for (int j = 0; j < cardWidth; j++)
	{
		if (j == cardWidth / 2)
		{
			COLOR_LOG(static_cast<int>(97), LOG, "DECK");
		}
		else
		{
			LOG_SPACE();
		}
	}
	LOG_EMPTY_LN();
}

void RenderText::PlayerTurnRender(bool secondPhase, vector<Card*> playerHand, vector<Card*> computerHand, Deck* deck)
{
	CLEAR_CONSOLE;
	if (!secondPhase)
	{
		LOG_EMPTY_LN();
		GREEN_COLOUR_LOG(LOG_LN, "             <=========== PLAYER'S TURN ==========>             ");
		LOG_EMPTY_LN();

		WHITE_COLOUR_LOG(LOG_LN, "Opponent hand: ");
		ShowOpponentHand(computerHand);
		ShowDiscardTop(deck->GetCurrentCard());
		LOG_EMPTY_LN();
		WHITE_COLOUR_LOG(LOG_LN, "Your hand: ");
		ShowPlayerHand(playerHand);
		LOG_EMPTY_LN();
		LOG_EMPTY_LN();
		LOG_EMPTY_LN();
		WHITE_COLOUR_LOG(LOG_LN, "Type the card number to play, or type '0' to pick a card:");
	}
	else
	{
		LOG_EMPTY_LN();
		GREEN_COLOUR_LOG(LOG_LN, "             <=========== PLAYER'S TURN ==========>             ");
		LOG_EMPTY_LN();

		WHITE_COLOUR_LOG(LOG_LN, "Opponent hand: ");
		ShowOpponentHand(computerHand);
		ShowDiscardTop(deck->GetCurrentCard());
		LOG_EMPTY_LN();
		WHITE_COLOUR_LOG(LOG_LN, "Your hand: ");
		ShowPlayerHand(playerHand);
		LOG_EMPTY_LN();
		LOG_EMPTY_LN();
		LOG_EMPTY_LN();
		WHITE_COLOUR_LOG(LOG_LN, "Your turn ended.");
		GRAY_COLOUR_LOG(LOG_LN, "[Press any key]");
	}
}

void RenderText::OpponentTurnRender(bool secondPhase, vector<Card*> computerHand, Deck* deck)
{
	CLEAR_CONSOLE;
	if (!secondPhase)
	{
		LOG_EMPTY_LN();
		RED_COLOUR_LOG(LOG_LN, "             <=========== OPPONENT'S TURN ==========>             ");
		LOG_EMPTY_LN();
		WHITE_COLOUR_LOG(LOG_LN, "Opponent hand: ");
		ShowOpponentHand(computerHand);
		ShowDiscardTop(deck->GetCurrentCard());
		LOG_EMPTY_LN();
		LOG_EMPTY_LN();
		WHITE_COLOUR_LOG(LOG_LN, "The opponent is playing . . . ");
		GRAY_COLOUR_LOG(LOG_LN, "[Press any key]");
	}
	else
	{
		LOG_EMPTY_LN();
		RED_COLOUR_LOG(LOG_LN, "             <=========== OPPONENT'S TURN ==========>             ");
		LOG_EMPTY_LN();
		WHITE_COLOUR_LOG(LOG_LN, "Opponent hand: ");
		ShowOpponentHand(computerHand);
		ShowDiscardTop(deck->GetCurrentCard());
		LOG_EMPTY_LN();
		LOG_EMPTY_LN();
		WHITE_COLOUR_LOG(LOG_LN, "The opponent finished their turn.");
		GRAY_COLOUR_LOG(LOG_LN, "[Press any key]");
	}
}

void RenderText::ShowResult(bool hasWon)
{
	CLEAR_CONSOLE;
	if (hasWon)
	{
		LOG_EMPTY_LN();
		RED_COLOUR_LOG(LOG_LN, "===========================================");
		GREEN_COLOUR_LOG(LOG_LN, "===========================================");
		WHITE_COLOUR_LOG(LOG_LN, "CONGRATULATIONS!!! YOU HAVE WON!!!");
		BLUE_COLOUR_LOG(LOG_LN, "===========================================");
		YELLOW_COLOUR_LOG(LOG_LN, "===========================================");
	}
	else
	{
		LOG_EMPTY_LN();
		RED_COLOUR_LOG(LOG_LN, "===========================================");
		RED_COLOUR_LOG(LOG_LN, "===========================================");
		WHITE_COLOUR_LOG(LOG_LN, "GAME OVER - YOU HAVE LOST.");
		RED_COLOUR_LOG(LOG_LN, "===========================================");
		RED_COLOUR_LOG(LOG_LN, "===========================================");
	}
}