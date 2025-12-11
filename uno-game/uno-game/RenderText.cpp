#include "RenderText.h"

void RenderText::PrintCards(Player& player)
{
	Hand cardsToPrint = player.GetHand();
	
	int cardWidth = 6;
	int cardHeight = 10;

	for (Card card : cardsToPrint)
	{
		// Prints top corner
		YELLOW_COLOUR_LOG(LOG(), "╭");
		for (int i = 0; i < cardWidth; i++)
		{
			YELLOW_COLOUR_LOG(LOG(), "-");
		}
		YELLOW_COLOUR_LOG(LOG(), "╮");

		LOG_SPACE(); // Space for the next card
	}
	LOG_EMPTY_LN(); // Go to next line of rendering

	for (int i = 0; i < cardHeight; i++)
	{
		for (Card card : cardsToPrint)
		{
			// Prints all of the card interior
			YELLOW_COLOUR_LOG(LOG(), "|");
			if (i == cardHeight / 2)
			{
				for (int j = 0; j < cardWidth; j++)
				{
					if (j == cardWidth / 2)
					{
						YELLOW_COLOUR_LOG(LOG(), card.GetSymbol());
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
			YELLOW_COLOUR_LOG(LOG(), "|");

			LOG_SPACE(); // Space for the next card
		}

		LOG_EMPTY_LN(); // Go to next line of rendering
	}

	for (Card card : cardsToPrint)
	{
		// Prints bottom corner
		YELLOW_COLOUR_LOG(LOG(), "╰");
		for (int i = 0; i < cardWidth; i++)
		{
			YELLOW_COLOUR_LOG(LOG(), "-");
		}
		YELLOW_COLOUR_LOG(LOG(), "╯");

		LOG_SPACE(); // Space for the next card
	}
	// Card render finished at this point



	//switch (card.GetColor())
	//{
	//case YELLOW:
	//	// Prints top corner
	//	YELLOW_COLOUR_LOG(LOG(), "╭");
	//	for (int i = 0; i < cardWidth; i++)
	//	{
	//		YELLOW_COLOUR_LOG(LOG(), "-");
	//	}
	//	YELLOW_COLOUR_LOG(LOG(), "╮");

	//	// Prints all of the card interior
	//	for (int i = 0; i < cardHeight; i++)
	//	{
	//		YELLOW_COLOUR_LOG(LOG(), "|");
	//		if (i == cardHeight / 2)
	//		{
	//			for (int j = 0; j < cardWidth; j++)
	//			{
	//				if (j == cardWidth / 2)
	//				{
	//					YELLOW_COLOUR_LOG(LOG(), card.GetSymbol());
	//				}
	//				else
	//				{
	//					LOG_EMPTY_LN();
	//				}
	//			}
	//		}
	//		else
	//		{
	//			for (int j = 0; j < cardWidth; j++)
	//			{
	//				LOG_EMPTY_LN();
	//			}
	//		}
	//		YELLOW_COLOUR_LOG(LOG(), "|");
	//	}

	//	// Prints bottom corner
	//	YELLOW_COLOUR_LOG(LOG(), "╰");
	//	for (int i = 0; i < cardWidth; i++)
	//	{
	//		YELLOW_COLOUR_LOG(LOG(), "-");
	//	}
	//	YELLOW_COLOUR_LOG(LOG(), "╯");
	//	break;
	//case RED:

	//	break;
	//case BLUE:

	//	break;
	//case GREEN:

	//	break;
	//default:
	//	break;
	//}
}

void RenderText::ShowPlayerHand(Card card)
{

}