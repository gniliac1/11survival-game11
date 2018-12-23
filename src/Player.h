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

	std::shared_ptr<sf::Sprite> getSprite();

private:

	Animation *_animation;
	std::unique_ptr<sf::Texture> _texture;
	std::shared_ptr<sf::Sprite> _sprite;
};

