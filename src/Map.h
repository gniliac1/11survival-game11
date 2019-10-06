#pragma once

// sfml tmxloader
#include<tmx/MapLoader.hpp>

class Map
{
public:

	// Construct a map by the path to the map files and the size of the window
	Map(const sf::FloatRect& windowRect, const std::string& mapPath = "../graphics/maps");

	// Empty standard destructor
	~Map();

	// Check for collisions of the player and map objects
	bool checkCollision(const sf::FloatRect& playerRect);

	// Check for possible zone switches
	bool checkZoneSwitch(const sf::Vector2f& playerPos);

	// Returns vector containing each layer of the map
	const std::vector<tmx::MapLayer>& getLayers() const;

	// Loads a tmx map from file
	bool load(const std::string& mapName);

private:

	// Map loader for loading maps in tmx format
	std::unique_ptr<tmx::MapLoader> _map;

	// Vector containing all objects in the part of he map which is shown on screen
	std::vector<tmx::MapObject*> _mapObjectsOnScreen;

	// Current size of the screen
	sf::FloatRect _windowRect;

public:

	// Set the rect of the screen 
	void setWindowRect(const sf::FloatRect& windowRect);
};

