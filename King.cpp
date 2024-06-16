#include "King.h"

void King::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("texture/King_White"));
		std::cerr << "Failed to load King_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("texture/King_Black"));
		std::cerr << "Failed to load King_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

King::King(bool isWhite) : Figure(isWhite)
{
	loadTexture();
}
