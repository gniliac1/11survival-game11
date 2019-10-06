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

	// constructor taking the initial position of the player as argument
	Player(const sf::Vector2f& positionOnScreen = sf::Vector2f(1800.0, 500.0));
	~Player();

	// moves the player according to the keyboard inputs considering the players velocity and the elapsed time since the last frame
	void move(float elapsedTime = 1.0);

	// resets the player's last move if this led to a collision with an object
	void resetLastMove();

	// perform the hit animation
	void hit();

	// enum containing the different viewing directions
	enum Direction
	{
		UP,
		LEFT,
		DOWN,
		RIGHT
	};

private:

	// stores the movement animation
	std::unique_ptr<Animation> _animationMove;

	// stores the hitting animation
	std::unique_ptr<Animation> _animationHit; // Blöder Name, soll aber die Animation über laufen sein^^

	// direction in which the player currently looks
	Direction _viewingDirection;

	// boolean variable indicating whether the hitting animation is currently performed
	bool _hitting;

	// current sprite of the player which is supposed to be drawn to the window
	std::shared_ptr<sf::Sprite> _curSprite;

public:

	// Returns the global bounding box for the person on the sprite, not for the whole sprite
	sf::FloatRect getBoundingBox();

	// Returns the current position of the player sprite
	sf::Vector2f getPosition() const;

	// returns the current sprite of the player
	std::shared_ptr<sf::Sprite> getSprite() const;

	// enable hitting
	void setHitting(bool isHitting);
};

