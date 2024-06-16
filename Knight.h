#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Figure.h"

class Knight final : public Figure
{
private:

	void loadTexture() override;

public:

	Knight(bool);
};
