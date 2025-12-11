#pragma once
#include "Utils.h"

// Colour of the card
enum Color {
	WILD = 37,
	RED = 91,
	GREEN,
	YELLOW,
	BLUE,
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

