#include "King.h"

void King::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("textures/King_White.png"));
		std::cerr << "Failed to load King_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("textures/King_Black.png"));
		std::cerr << "Failed to load King_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

King::King(bool isWhite) : Figure(isWhite)
{
	loadTexture();
}

std::vector<sf::Vector2i> King::availableMove()
{
	return { {0,0} };
}
