// Starts game manager
#include "Computer.h"
#include "RenderText.h"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"

int main()
{
	RenderText renderer;
	renderer.ShowOpponentHand();
	renderer.ShowPlayerHand();


	// TEST BLOCK REMOVE LATER
	Deck* deck = new Deck();
	Hand hand(deck);
	vector<Card*> cardsToPrint = hand.GetCards();

	renderer.ShowDiscardTop(cardsToPrint[0]);

	renderer.PlayerTurnRender(false);
	renderer.OpponentTurnRender(false);

	renderer.ShowResult(false);
	renderer.ShowResult(true);

}