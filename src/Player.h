#pragma once

// standard c++ header
#include<iostream>
#include<memory>

// sfml header
#include<SFML/Graphics.hpp>

// own header files
#include "UserTypes.h"

class Player
{
public:
	Player();
	~Player();

	void move();

	std::shared_ptr<sf::Sprite> getSprite();

private:

	std::unique_ptr<sf::Texture> _texture;
	std::shared_ptr<sf::Sprite> _sprite;
};

