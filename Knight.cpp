#include "Knight.h"

void Knight::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("texture/Knight_White"));
		std::cerr << "Failed to load Knight_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("texture/Knight_Black"));
		std::cerr << "Failed to load Knight_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Knight::Knight(bool isWhite) : Figure(isWhite)
{
	loadTexture();
}
