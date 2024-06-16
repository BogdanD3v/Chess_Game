#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Figure.h"
#include "Pawn.h"

class Board
{
private:

	std::vector<std::vector<Figure*>> figures;

	int fieldSize;

	sf::Sprite sprite;
	sf::Texture texture;

	void loadTexture();

	void initializeFigures();

public:

	Board();
	~Board();

	void draw(sf::RenderWindow*);
};

