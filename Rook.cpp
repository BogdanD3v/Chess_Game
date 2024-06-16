#include "Rook.h"

void Rook::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("textures/Rook_White.png"));
		std::cerr << "Failed to load Rook_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("textures/Rook_Black.png"));
		std::cerr << "Failed to load Rook_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Rook::Rook(bool isWhite) : Figure(isWhite)
{
	loadTexture();
}
