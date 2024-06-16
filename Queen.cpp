#include "Queen.h"

void Queen::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("texture/Queen_White"));
		std::cerr << "Failed to load Queen_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("texture/Queen_Black"));
		std::cerr << "Failed to load Queen_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Queen::Queen(bool isWhite) : Figure(isWhite)
{
	loadTexture();
}
