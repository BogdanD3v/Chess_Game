#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Figure.h"

class Pawn final : public Figure
{
private:

	bool isFirstMove;

	void loadTexture() override;

public:

	Pawn(bool);

	void setIsNextMove();

	std::vector<sf::Vector2i> availableMove() override;
};

