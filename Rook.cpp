#include "Rook.h"

void Rook::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("texture/Rook_White"));
		std::cerr << "Failed to load Rook_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("texture/Rook_Black"));
		std::cerr << "Failed to load Rook_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Rook::Rook(bool isWhite) : Figure(isWhite)
{
	loadTexture();
}
