#include "Figure.h"

Figure::Figure(bool _isWhite) : isWhite(_isWhite) { sprite.scale(1.5, 1.5); }

void Figure::draw(sf::RenderWindow* window, sf::Vector2f position)
{
	sprite.setPosition(position);
	window->draw(sprite);
}

void Figure::initializeFiguresVector(std::vector<std::vector<Figure*>> _figures)
{
	figures = _figures;
}
