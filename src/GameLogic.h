#pragma once

// sfml headers
#include <SFML/Graphics.hpp>

// own headers
#include "Map.h"
#include "Player.h"

class GameLogic
{

public:

	GameLogic(const sf::FloatRect& windowRect, std::string startZoneName="markt.tmx");
	~GameLogic();

	// updates the GameLogic with the elapsed time since the last tick
	void update(float elapsedTime);

private:

	// Map instance storing the current zone in which the Player interacts
	std::unique_ptr<Map> _currentZone;

	// Instance containing the information about the player
	std::unique_ptr<Player> _player;

	// Switch the zones (load a new map)
	void switchZones();

};

