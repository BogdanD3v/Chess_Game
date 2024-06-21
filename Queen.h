#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Figure.h"

class Queen final : public Figure
{
private:

	void loadTexture() override;

public:

	Queen(bool);

	std::vector<sf::Vector2i> availableMove() override;
};

