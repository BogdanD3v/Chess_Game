#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	void initializeWindow();

public:

	Game();
	virtual ~Game();

	const bool running() const;

	void pollEvents();
	void update();
	void render();
};

