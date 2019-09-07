#pragma once

// sfml header
#include<SFML/Graphics.hpp>

// own header
#include "Image.h"

class Animation /*: public Image*/
{
public:

	//Animation(std::string textureFileName, sf::IntRect hitBox, sf::Vector2f position, sf::IntRect rectOfAnimationForSprite, sf::IntRect rectOfTextureForAnimation);
	Animation(sf::IntRect rect = sf::IntRect(0, 640, 64, 64)); // old, 640 = 10*64
	~Animation(); // old

	sf::IntRect moveSprite(int pressedKey); // old
	void moveSprite(int pressedKey, std::shared_ptr<sf::Sprite> sprite); // old
	void reset(std::shared_ptr<sf::Sprite> sprite); // old

private:

	sf::IntRect _rectOfSprite; // old

public:

	sf::IntRect getRectOfSprite(); // old

	//void setPosition(const sf::Vector2f& position);

};

