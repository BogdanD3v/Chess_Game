#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Figure.h"

class Pawn final : public Figure
{
private:

	void loadTexture() override;

public:

	Pawn(bool);

	std::vector<sf::Vector2i> availableMove() override;
};

