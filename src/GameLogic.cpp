#include "pch.h"
#include "GameLogic.h"


GameLogic::GameLogic(const sf::FloatRect& windowRect, std::string startZoneName)
	: _currentZone(std::make_unique<Map>(windowRect)),
	_player(std::make_unique<Player>(sf::Vector2f(1800.f, 500.f)))
{
	// load the map
	_currentZone->load(startZoneName);
}


GameLogic::~GameLogic()
{
}

void GameLogic::update(float elapsedTime)
{
	// add stuff here, which has to be updated in each tic

	// move player
	_player->move();

	// check for collision with map objects
	if (_currentZone->checkCollision(_player->getBoundingBox())) {
		// if collisions are detected, reset the last move
		_player->resetLastMove();
	}

	// check for zone switches
	if (_currentZone->checkZoneSwitch(_player->getPosition())) {
		// perform the zone switch
		switchZones();
	}
}

void GameLogic::switchZones()
{
	// TODO:
	// - implement the zone switch by loading the new map
	// - the name of the new map should be obtained from an additional map file which is read in when loading the map
	// - the name is then used, to load the new map after the unique_ptr has been reset
}
