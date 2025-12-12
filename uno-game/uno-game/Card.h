#pragma once
#include "Utils.h"

// Colour of the card
enum Color {
	RED = 91,
	GREEN,
	YELLOW,
	BLUE,
	WILD = 97,
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

