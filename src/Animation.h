#pragma once

// sfml header
#include<SFML/Graphics.hpp>

// own header
#include "Image.h"

class Animation : public Image
{
public:

	Animation(std::string textureFileName, sf::IntRect hitBox, sf::Vector2f position, sf::IntRect rectOfAnimationForSprite, sf::IntRect rectOfTextureForAnimation = sf::IntRect());
	Animation(sf::IntRect rect = sf::IntRect(0, 129, 64, 64)); // old
	~Animation(); // old

	sf::IntRect moveSprite(int pressedKey); // old
	void moveSprite(int pressedKey, std::shared_ptr<sf::Sprite> sprite); // old

private:

	sf::IntRect _rectOfSprite; // old

public:

	sf::IntRect getRectOfSprite(); // old

	void setPosition(const sf::Vector2f& position);

};

