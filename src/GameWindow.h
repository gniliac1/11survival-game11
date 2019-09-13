#pragma once

// standard c++ header
#include<deque> // for deque
#include<memory> // for smart pointers

// sfml header
#include<SFML/Graphics.hpp>

// sfml tmxloader
#include<tmx/MapLoader.hpp>

// own header files
#include "GameLog.h"
#include "Player.h"
#include "UserTypes.h"

class GameWindow
{
public:

	// constructor
	GameWindow(size_t width=1920, size_t height=1080, cdouble frameRate=30, cstring windowTitle="Survival Game");
	// destructor
	~GameWindow();

	// this function contains the program loop
	void run();

private:

	std::string _objectLabel;

	// true when an interaction is issued, else false
	bool _interactionRequest;

	// font for writing status messages
	sf::Font _statusFont;

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

	// check collisions
	void check_collisions();

	// perform graphic specific operations
	void render();

	// Shows a label above the charakter to label the object in front of him
	void showObjectLabel(std::string label);

	// writes the currently active status messages to the screen
	void showStatusMessages();

};

