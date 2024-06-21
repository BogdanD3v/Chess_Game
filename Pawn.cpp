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

std::vector<sf::Vector2i> Pawn::availableMove()
{
	int xIndex = sprite.getPosition().x / 100;
	int yIndex = sprite.getPosition().y / 100;

	std::vector<sf::Vector2i> coordinates;

	if (isWhite)
	{
		coordinates.push_back({ xIndex,yIndex - 1 });
		coordinates.push_back({ xIndex,yIndex - 2 });
	}
	else
	{
		coordinates.push_back({ xIndex,yIndex + 1 });
		coordinates.push_back({ xIndex,yIndex + 2 });
	}

	return coordinates;
}
