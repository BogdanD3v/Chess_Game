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

	void draw(sf::RenderWindow*, sf::Vector2f) override;
};

