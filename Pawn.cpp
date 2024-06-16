#include "Pawn.h"

void Pawn::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("texture/Pawn_White"));
			std::cerr << "Failed to load Pawn_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("texture/Pawn_Black"));
			std::cerr << "Failed to load Pawn_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Pawn::Pawn(bool isWhite) : Figure(isWhite) 
{
	loadTexture();
}

void Pawn::draw(sf::RenderWindow* window, sf::Vector2f position)
{
	sprite.setPosition(position);
	window->draw(sprite);
}
