#include "Queen.h"

void Queen::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("textures/Queen_White.png"))
		std::cerr << "Failed to load Queen_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("textures/Queen_Black.png"))
		std::cerr << "Failed to load Queen_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Queen::Queen(bool isWhite) : Figure(isWhite)
{
	loadTexture();
}

std::vector<sf::Vector2i> Queen::availableMove()
{
	return { {0,0} };
};

