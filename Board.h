#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Figure.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

class Board
{
private:

	Figure* choosenFigure;

	std::vector<std::vector<Figure*>> figures;
	std::vector<sf::Vector2i> highlightedSpots;

	sf::Vector2i mousePosition;
	sf::Sprite sprite;
	sf::Texture texture;

	int fieldSize;

	void loadTexture();

	void initializeVector();

	void initializeFigures();

public:

	Board();
	virtual ~Board();

	void draw(sf::RenderWindow*);

	void onClick(sf::Vector2i);

	void drawAvailableMove(sf::RenderWindow*);
};

