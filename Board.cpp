#include "Board.h"

void Board::loadTexture()
{
	if (!texture.loadFromFile("textures/Board.png"))
		std::cerr << "Failed to load Board texture!" << "\n";

	sprite.setTexture(texture);
}

void Board::initializeVector()
{
	figures.resize(8);

	for (int i = 0; i < 8; i++)
	{
		figures[i].resize(8);
	}
}

void Board::initializeFigures()
{
	for (int i = 0; i < 8; i++)
	{
		figures[1][i] = new Pawn(false);
		figures[6][i] = new Pawn(true);
	}

	figures[0][0] = new Rook(false);
	figures[0][7] = new Rook(false);
	figures[7][0] = new Rook(true);
	figures[7][7] = new Rook(true);

	figures[0][1] = new Knight(false);
	figures[0][6] = new Knight(false);
	figures[7][1] = new Knight(true);
	figures[7][6] = new Knight(true);

	figures[0][2] = new Bishop(false);
	figures[0][5] = new Bishop(false);
	figures[7][2] = new Bishop(true);
	figures[7][5] = new Bishop(true);

	figures[0][3] = new King(false);
	figures[7][3] = new King(true);

	figures[0][4] = new Queen(false);
	figures[7][4] = new Queen(true);
}

Board::Board() : fieldSize(100)
{
	loadTexture();
	initializeVector();
	initializeFigures();
}

Board::~Board()
{
	for (auto const& row : figures)
		for (auto const& figure : row)
			delete figure;
}

void Board::draw(sf::RenderWindow* window)
{
	window->draw(sprite);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figures[i][j] != nullptr)
				figures[i][j]->draw(window, sf::Vector2f( j * fieldSize + 3, i * fieldSize + 3 ));
		}
	}
}
