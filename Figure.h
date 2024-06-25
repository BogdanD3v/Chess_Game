#pragma once

#include <SFML/Graphics.hpp>

class Figure
{
protected:

	bool isWhite;

	sf::Sprite sprite;
	sf::Texture texture;

	std::vector<std::vector<Figure*>> figures;

	virtual void loadTexture() = 0;

public:

	Figure(bool);
	virtual ~Figure() = default;

	virtual std::vector<sf::Vector2i> availableMove() = 0;

	void draw(sf::RenderWindow*, sf::Vector2f);

	void initializeFiguresVector(std::vector<std::vector<Figure*>>);
};

