#include "RenderText.h"

void RenderText::PrintCards(Player& player)
{
	Hand playerHand = player.GetHand();
	vector<Card> cardsToPrint = playerHand.GetCards();
	
	int cardWidth = 6;
	int cardHeight = 10;

	// ---- RENDERING: FIRST LINE ------------------------------------
	for (Card card : cardsToPrint)
	{
		// Prints top corner
		COLOR_LOG(static_cast<int>(card.GetColor()), LOG, "╭");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(card.GetColor()), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(card.GetColor()), LOG, "╮");

		LOG_SPACE(); // Space for the next card
	}
	LOG_EMPTY_LN(); // Go to next line of rendering

	// ---- RENDERING: MIDDLE LINES ------------------------------------
	for (int i = 0; i < cardHeight; i++)
	{
		for (Card card : cardsToPrint)
		{
			// Prints all of the card interior
			COLOR_LOG(static_cast<int>(card.GetColor()), LOG, "|");
			if (i == cardHeight / 2)
			{
				for (int j = 0; j < cardWidth; j++)
				{
					if (j == cardWidth / 2)
					{
						COLOR_LOG(static_cast<int>(card.GetColor()), LOG, card.GetSymbol());
					}
					else
					{
						LOG_SPACE();
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
			COLOR_LOG(static_cast<int>(card.GetColor()), LOG, "|");

			LOG_SPACE(); // Space for the next card
		}

		LOG_EMPTY_LN(); // Go to next line of rendering
	}

	// ---- RENDERING: LAST LINE ------------------------------------
	for (Card card : cardsToPrint)
	{
		// Prints bottom corner
		COLOR_LOG(static_cast<int>(card.GetColor()), LOG, "╰");
		for (int i = 0; i < cardWidth; i++)
		{
			COLOR_LOG(static_cast<int>(card.GetColor()), LOG, "-");
		}
		COLOR_LOG(static_cast<int>(card.GetColor()), LOG, "╯");

		LOG_SPACE(); // Space for the next card
	}
	// Card render finished at this point
}

void RenderText::ShowPlayerHand(Card card)
{

}