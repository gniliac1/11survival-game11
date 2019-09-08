#pragma once

// standard c++ header
#include<iostream>
#include<memory>

// own header files
#include "UserTypes.h"
#include "Animation.h"

class Player
{
public:
	Player();
	~Player();

	void move();
	void resetLastMove();
	//Returns the global bounding box for the human. Not for the whole sprite.
	sf::FloatRect getBoundingBox(); 
	std::shared_ptr<sf::Sprite> getSprite() const;

private:

	Animation *_animation;
};

