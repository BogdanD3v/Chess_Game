#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Figure.h"

class Rook final : public Figure
{
private:

	void loadTexture() override;

public:

	Rook(bool);

	std::vector<sf::Vector2i> availableMove() override;
};

