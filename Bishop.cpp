#include "Bishop.h"

void Bishop::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("texture/Bishop_White"));
		std::cerr << "Failed to load Bishop_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("texture/Bishop_Black"));
		std::cerr << "Failed to load Bishop_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Bishop::Bishop(bool isWhite) : Figure(isWhite)
{
	loadTexture();
}
