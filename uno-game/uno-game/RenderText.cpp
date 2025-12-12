#include "RenderText.h"

void RenderText::ShowPlayerHand()
{
	// For testing:
	Deck* deck = new Deck();
	Hand hand(deck);
	vector<Card*> cardsToPrint = hand.GetCards();
	
	int cardWidth = 5;
	int cardHeight = 3;

	LOG_EMPTY_LN();

	// ---- RENDERING: FIRST LINE ------------------------------------
	for (Card* card : cardsToPrint)
	{
		// Prints top corner
		COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "╭");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "╮");

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
		COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "╰");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(card->GetColor()), LOG, "╯");

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

void RenderText::ShowOpponentHand()
{
	// For testing:
	Deck* deck = new Deck();
	Hand hand(deck);
	vector<Card*> cardsToPrint = hand.GetCards();

	int cardWidth = 5;
	int cardHeight = 3;

	LOG_EMPTY_LN();

	// ---- RENDERING: FIRST LINE ------------------------------------
	for (Card* card : cardsToPrint)
	{
		// Prints top corner
		COLOR_LOG(static_cast<int>(37), LOG, "╭");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(37), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(37), LOG, "╮");

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
		COLOR_LOG(static_cast<int>(37), LOG, "╰");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(37), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(37), LOG, "╯");

		LOG_SPACE(); // Space for the next card
	}
}

void RenderText::ShowDeckTop(bool visible)
{
	int cardWidth = 5;
	int cardHeight = 3;
	
	if (!visible)
	{
		LOG_EMPTY_LN();
		// Prints top corner
		COLOR_LOG(static_cast<int>(37), LOG, "╭");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(37), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(37), LOG, "╮");

		LOG_SPACE(); // Space for the next card
		LOG_EMPTY_LN(); // Go to next line of rendering

		// ---- RENDERING: MIDDLE LINES ------------------------------------
		for (int i = 0; i < cardHeight; i++)
		{
			// Prints all of the card interior
			COLOR_LOG(static_cast<int>(37), LOG, "|");
			for (int j = 0; j < cardWidth; j++)
			{
				COLOR_LOG(static_cast<int>(37), LOG, "-");
			}
			COLOR_LOG(static_cast<int>(37), LOG, "|");

			LOG_SPACE(); // Space for the next card

			LOG_EMPTY_LN(); // Go to next line of rendering
		}

		// Prints bottom corner
		COLOR_LOG(static_cast<int>(37), LOG, "╰");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(37), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(37), LOG, "╯");

		LOG_SPACE(); // Space for the next card
	}
	else
	{
		// PRINT VISIBLE TOP CARD
	}

	LOG_EMPTY_LN();

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
}

//void RenderText::PlayerTurnRender()
//{
//	GREEN_COLOUR_LOG(LOG_LN, "             <=========== PLAYER'S TURN ==========>             ");
//
//	
//	ShowPlayerHand();
//}
//
//void RenderText::PlayerTurnRender()
//{
//	RED_COLOUR_LOG(LOG_LN, "             <=========== OPPONENT'S TURN ==========>             ");
//
//
//}