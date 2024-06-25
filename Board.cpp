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

	availableMovement.resize(8);

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

Board::Board() : fieldSize(100), mousePosition({0,3})
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

void Board::onClick(sf::Vector2i _mousePosition)
{
	mousePosition.y = _mousePosition.y / fieldSize;
	mousePosition.x = _mousePosition.x / fieldSize;

	figure->initializeFiguresVector(figures);

	Pawn* pawn = dynamic_cast<Pawn*>(choosenFigure);

	bool isAvailableMoveClicked = false;

	for (auto const& el : availableMovement)
	{
		if (el.x == mousePosition.x && el.y == mousePosition.y)
			isAvailableMoveClicked = true;

	}

	if (figures[mousePosition.y][mousePosition.x] != nullptr && !isAvailableMoveClicked)
	{
		availableMovement = figures[mousePosition.y][mousePosition.x]->availableMove();

		if (pawn)
		{
			for (auto const& el : pawn->availableCapture())
			{
				if (figures[el.y][el.x] != nullptr)
				{
					availableMovement.push_back(el);
				}
			}
		}

		choosenFigure = figures[mousePosition.y][mousePosition.x];
	}
	else
	{
		bool figureRejected = false;
		bool enemyRejected = false;

		for (auto const& el : availableMovement)
		{
			if (mousePosition.x == el.x && mousePosition.y == el.y)
			{
				for (int i = 0; i < figures.size(); i++)
				{
					for (int j = 0; j < figures[i].size(); j++)
					{
						if (figures[i][j] == choosenFigure)
						{
							figures[i][j] = nullptr;
							figureRejected = true;
						}
						if (figures[el.y][el.x] != nullptr)
						{
							figures[el.y][el.x] = nullptr;
							enemyRejected = true;
						}
						if (enemyRejected && figureRejected)
							break;
					}
				}

				isAvailableMoveClicked = false;

				if (pawn)
				{
					pawn->setIsNextMove();
				}

				figures[mousePosition.y][mousePosition.x] = choosenFigure;
				choosenFigure = nullptr;

				availableMovement.clear();

				break;
			}
		}
	}
}

void Board::drawAvailableMove(sf::RenderWindow* window)
{
	if (figures[mousePosition.y][mousePosition.x] != nullptr)
	{
		Pawn* pawn = dynamic_cast<Pawn*>(choosenFigure);

		if (pawn)
		{
			for (auto const& el : pawn->availableCapture())
			{
				if (figures[el.y][el.x] != nullptr)
				{
					availableMovement.push_back(el);
				}
			}
		}

		for (int i = 0; i < availableMovement.size(); i++)
		{
			sf::RectangleShape rectangle;

			if (figures[availableMovement[i].y][availableMovement[i].x] != nullptr)
			{
				rectangle.setFillColor(sf::Color(0, 0, 0, 0));
				rectangle.setOutlineColor(sf::Color(255, 0, 0, 255));
				rectangle.setOutlineThickness(5);
			}
			else rectangle.setFillColor(sf::Color(0, 255, 255, 100));

			rectangle.setSize({ 100,100 });
			rectangle.setPosition(availableMovement[i].x * 100, availableMovement[i].y * 100);
			window->draw(rectangle);
		}
	}
}
