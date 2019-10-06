#include "pch.h"
#include "Map.h"


Map::Map(const sf::FloatRect& windowRect, const std::string& mapPath)
	: _map(std::make_unique<tmx::MapLoader>(mapPath)),
	 _windowRect(windowRect)
{
}

Map::~Map()
{
}

bool Map::checkCollision(const sf::FloatRect& playerRect)
{
	// query the quad tree with the bounding box of the player
	_mapObjectsOnScreen = _map->queryQuadTree(playerRect);

	// check whether the player rect is inside the window rect
	if (playerRect.left < _windowRect.left || playerRect.left + playerRect.width > _windowRect.left + _windowRect.width ||
		playerRect.top < _windowRect.top || playerRect.top + playerRect.height > _windowRect.top + _windowRect.height)
	{
		return true;
	}

	// iterate over all objects in the map
	for (const tmx::MapObject* object : _mapObjectsOnScreen)
	{
		// check whether the collision boxes intersect
		if (object->getAABB().intersects(playerRect))
		{
			// collision detected
			return true;
		}
	}
}

bool Map::checkZoneSwitch(const sf::Vector2f & playerPos)
{
	// TODO:
	// - not implemented yet
	// - check whether the current position of the player allows for zone switches 
	// - the possible locations of zone switches have been read in from a map 
	// - this functionality still needs to be implemented as well
	return false;
}

const std::vector<tmx::MapLayer>& Map::getLayers() const
{
	return _map->getLayers();
}

bool Map::load(const std::string& mapName)
{
	// load the map
	if (_map->load(mapName))
	{
		// update the quad tree with the current window size
		_map->updateQuadTree(_windowRect);

		return true;
	}
	else
	{
		return false;
	}
}

void Map::setWindowRect(const sf::FloatRect & windowRect)
{
	_windowRect = windowRect;

	// update the quad tree with the new window size
	_map->updateQuadTree(_windowRect);
}
