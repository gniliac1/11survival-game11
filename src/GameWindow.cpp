#include "pch.h"
#include "GameWindow.h"


GameWindow::GameWindow(size_t width, size_t height, cdouble frameRate, cstring windowTitle)
	: _player( std::make_unique<Player>() ) ,
	_window( std::make_unique<sf::RenderWindow>( sf::VideoMode(width,height) , windowTitle) )
{
	_window->setFramerateLimit(frameRate);
}

GameWindow::~GameWindow()
{
}

void GameWindow::run()
{
	while (_window->isOpen())
	{
		manageEvents();

		logic();

		render();
	}
}

void GameWindow::manageEvents()
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
		// catch the resize events
		if (event.type == sf::Event::Resized)
		{
			// update the view to the new size of the window
			sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
			_window->setView(sf::View(visibleArea));
		}

		if (event.type == sf::Event::Closed)
		{
			_window->close();
		}
	}
}

void GameWindow::logic()
{
	_player->move();
}

void GameWindow::render()
{
	_window->clear();

	// draw the scene
	_window->draw( *_player->getSprite() );

	_window->display();
}