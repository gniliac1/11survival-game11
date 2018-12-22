#pragma once

// standard c++ header
#include<memory>

// sfml header
#include<SFML/Graphics.hpp>

// own header files
#include "Player.h"
#include "UserTypes.h"

class GameWindow
{
public:

	// constructor
	GameWindow(size_t width=960, size_t height=540, cdouble frameRate=60, cstring windowTitle="Survival Game");
	// destructor
	~GameWindow();

	// this function contains the program loop
	void run();

private:

    // pointer to the playable charakter
	std::unique_ptr<Player> _player;

	// pointer to the window instance
	std::unique_ptr<sf::RenderWindow> _window;

	// event manager
	void manageEvents();

	// move objects and check collisions
	void logic();

	// perform graphic specific operations
	void render();

};

