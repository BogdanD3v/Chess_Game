#include "Game.h"

void Game::initializeWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Chess Game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

Game::Game()
{
	this->initializeWindow();
}

Game::~Game()
{

}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:

			this->window->close();

		case sf::Event::KeyPressed:

			switch (this->event.key.code)
			{
			case sf::Keyboard::Escape:

				this->window->close();
			}
		case sf::Event::MouseButtonPressed:

			board.onClick(sf::Mouse::getPosition(*this->window));
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear(sf::Color::Black);

	board.draw(this->window);

	board.drawAvailableMove(this->window);

	this->window->display();
}
