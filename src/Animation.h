#pragma once

// sfml header
#include<SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::IntRect rect = sf::IntRect(0, 0, 64, 64));
	~Animation();

	sf::IntRect moveSprite(int pressedKey);
	void moveSprite(int pressedKey, std::shared_ptr<sf::Sprite> sprite);

private:
	sf::IntRect _rectOfSprite;

public:
	sf::IntRect getRectOfSprite();

};

