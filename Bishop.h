#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Figure.h"

class Bishop final : public Figure
{
private:

	void loadTexture() override;

public:

	Bishop(bool);
};

