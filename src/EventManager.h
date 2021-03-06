#pragma once

#include <SFML/Graphics.hpp>

class EventManager
{
public:

	EventManager(const std::shared_ptr<sf::RenderWindow> gameWindow);
	~EventManager();

	void checkForEvents();

private:

	// Pointer to the render window instance
	std::shared_ptr<sf::RenderWindow> _gameWindow;

	// Pointer to the character instance
	//std::shared_ptr<Character> _character;

};

