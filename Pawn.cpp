#include "Pawn.h"

void Pawn::loadTexture()
{
	if (isWhite == true)
	{
		if (!texture.loadFromFile("textures/Pawn_White.png"))
			std::cerr << "Failed to load Pawn_White texture!" << "\n";
	}
	else
	{
		if (!texture.loadFromFile("textures/Pawn_Black.png"))
			std::cerr << "Failed to load Pawn_Black texture!" << "\n";
	}

	sprite.setTexture(texture);
}

Pawn::Pawn(bool isWhite) : Figure(isWhite), isFirstMoveBlack(false), isFirstMoveWhite(false)
{
	loadTexture();
}

void Pawn::setIsNextMove()
{
	if (isWhite)
		isFirstMoveWhite = true;
	else
		isFirstMoveBlack = true;
}

std::vector<sf::Vector2i> Pawn::availableCapture()
{
	int xIndex = sprite.getPosition().x / 100;
	int yIndex = sprite.getPosition().y / 100;

	std::vector<sf::Vector2i> coordinates;

	if (isWhite)
	{
		coordinates.push_back({ xIndex + 1,yIndex - 1 });
		coordinates.push_back({ xIndex - 1,yIndex - 1 });
	}
	else
	{
		coordinates.push_back({ xIndex + 1,yIndex + 1 });
		coordinates.push_back({ xIndex - 1,yIndex + 1 });
	}

	return coordinates;
}

std::vector<sf::Vector2i> Pawn::availableMove()
{
	int xIndex = sprite.getPosition().x / 100;
	int yIndex = sprite.getPosition().y / 100;

	Board board;

	std::vector<sf::Vector2i> coordinates;
	std::vector<std::vector<Figure*>> figures = board.getFigures();

	auto checkIsAvailable = [&figures, &coordinates](int x, int y) {if (figures[y][x] == nullptr) { coordinates.push_back({ x, y }); }; };

	if (!isFirstMoveWhite && isWhite)
	{
		checkIsAvailable(xIndex, yIndex - 1);
		checkIsAvailable(xIndex, yIndex - 2);
	}
	else if (!isFirstMoveBlack && !isWhite)
	{
		checkIsAvailable(xIndex, yIndex + 1);
		checkIsAvailable(xIndex, yIndex + 2);
	}
	else if (isFirstMoveWhite && isWhite)
	{
		checkIsAvailable(xIndex, yIndex - 1);
	}
	else if (isFirstMoveBlack && !isWhite)
	{
		checkIsAvailable(xIndex, yIndex + 1);
	}	

	return coordinates;
}
