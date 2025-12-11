#pragma once
#include "Card.h"

// Constructor, sets the card color and symbol
Card::Card(Color color, string symbol) :
	_color(color),
	_symbol(symbol)
{ }

// Gets color of card
Color Card::GetColor()
{
	return _color;
}

// Gets symbol of card
string Card::GetSymbol()
{
	return _symbol;
}
