#include "pch.h"
#include "GameGraphics.h"


GameGraphics::GameGraphics(size_t width, size_t height, double frameRate, const std::string& windowTitle)
	: _gameWindow( std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), windowTitle) )
{
	// window options
	_gameWindow->setFramerateLimit(frameRate);
}


GameGraphics::~GameGraphics()
{
}

void GameGraphics::renderScene(const std::deque<std::shared_ptr<sf::Drawable>>& sceneObjects)
{
	// clear the window
	_gameWindow->clear();

	// iterate over all objects and draw them to the screen
	for (auto object : sceneObjects) {
		_gameWindow->draw(*object);
	}

	// draw everything to the screen
	_gameWindow->display();
}

std::shared_ptr<sf::RenderWindow> GameGraphics::getGameWindow()
{
	return _gameWindow;
}
