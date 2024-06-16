#include "Board.h"

void Board::loadTexture()
{
	if (!texture.loadFromFile("textures/Board.png"))
		std::cerr << "Failed to load Board texture!" << "\n";
}

void Board::initializeFigures()
{
	for (int i = 0; i < 8; i++)
		figures[1][i] = new Pawn(false);
}

Board::Board() : fieldSize(10)
{
	loadTexture();
	figures.resize(8);
	for (int i = 0; i < 8; i++)
	{
		figures[i].resize(8);
	}
	sprite.setTexture(texture);
}

Board::~Board()
{

}

void Board::draw(sf::RenderWindow* window)
{
	window->draw(sprite);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figures[i][j] != nullptr)
				figures[i][j]->draw(window, sf::Vector2f( j * fieldSize, i * fieldSize ));
		}
	}
}
