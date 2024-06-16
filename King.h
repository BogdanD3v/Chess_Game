#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Figure.h"

class King final : public Figure
{
private:

	void loadTexture() override;

public:

	King(bool);
};

