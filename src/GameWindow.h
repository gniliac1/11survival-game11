#pragma once

// standard c++ header
#include<memory>

// sfml header
#include<SFML/Graphics.hpp>

// sfml tmxloader
#include<tmx/MapLoader.hpp>

// own header files
#include "Player.h"
#include "UserTypes.h"

class GameWindow
{
public:

	// constructor
	GameWindow(size_t width=1920, size_t height=1080, cdouble frameRate=60, cstring windowTitle="Survival Game");
	// destructor
	~GameWindow();

	// this function contains the program loop
	void run();

private:

	// pointer to the map instance
	std::unique_ptr<tmx::MapLoader> _map;

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

