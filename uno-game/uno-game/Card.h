#pragma once
#include "Utils.h"

// Colour of the card
enum Color {
	RED,
	BLUE,
	YELLOW,
	GREEN,
	WILD
};


class Card
{
public:

	// Constructor
	Card(Color color, string symbol);

	// Getters
	Color GetColor();
	string GetSymbol();

private:

	Color _color;
	string _symbol;

};

