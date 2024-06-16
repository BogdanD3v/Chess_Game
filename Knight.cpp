#include "Knight.h"

void Knight::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("textures/Knight_White.png"));
		std::cerr << "Failed to load Knight_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("textures/Knight_Black.png"));
		std::cerr << "Failed to load Knight_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Knight::Knight(bool isWhite) : Figure(isWhite)
{
	loadTexture();
}
