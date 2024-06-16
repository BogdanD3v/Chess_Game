#include "Pawn.h"

void Pawn::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("textures/Pawn_White.png"));
			std::cerr << "Failed to load Pawn_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("textures/Pawn_Black.png"));
			std::cerr << "Failed to load Pawn_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Pawn::Pawn(bool isWhite) : Figure(isWhite) 
{
	loadTexture();
}