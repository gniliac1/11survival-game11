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
	void hit();
	//Returns the global bounding box for the human. Not for the whole sprite.
	sf::FloatRect getBoundingBox(); 
	std::shared_ptr<sf::Sprite> getSprite() const;
	void setHitting(bool isHitting);

	enum Direction
	{
		UP,
		LEFT,
		DOWN,
		RIGHT
	};

private:

	Animation *_animationMove;
	Animation *_animationHit; //Blöder Name, soll aber die Animation über laufen sein^^

	int _viewingDirection;
	bool _hitting;

	std::shared_ptr<sf::Sprite> _curSprite;
};

