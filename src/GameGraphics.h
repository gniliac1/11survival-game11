#pragma once

// standard c++ header
#include <deque> // for deque

// sfml headers
#include <SFML/Graphics.hpp>

class GameGraphics
{

public:

	GameGraphics(size_t width = 1920, size_t height = 1080, double frameRate = 60, const std::string& windowTitle = "Survival Game");
	~GameGraphics();

	// Render all objects which form the current scene that is displayed on the screen 
	void renderScene(const std::deque<std::shared_ptr<sf::Drawable>>& sceneObjects);

private:

	// The game window on which is shown to the user
	std::shared_ptr<sf::RenderWindow> _gameWindow;

public:

	// Return a pointer to the current window
	std::shared_ptr<sf::RenderWindow> getGameWindow();
};

