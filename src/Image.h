#pragma once

// std library
#include <iostream> // std::cerr
#include <memory> // std::unique_pointer

// sfml header
#include <SFML/Graphics.hpp>

class Image
{
public: 

	Image(std::string textureFileName, sf::IntRect hitBox, sf::Vector2f position, sf::IntRect rectOfTextureForSprite = sf::IntRect());
	virtual ~Image();

protected: 

	// Charakter hat Hitbox von 24x24 mit top=40 und left=20
	sf::IntRect _hitBox;
	std::shared_ptr<sf::Sprite> _sprite;	// Bild des (animierten) Objektes. Besitzt eine Position.
	std::unique_ptr<sf::Texture> _texture;	// Menge aber Bilder, quasi das "Spritesheet" bzw. ein Teil vom Spritesheet.

public: 

	sf::FloatRect getGlobalHitBox() const;
	sf::Vector2f getPosition() const;
	std::shared_ptr<sf::Sprite> getSprite() const;

	//void setPosition(const sf::Vector2f& position);
};

