#pragma once

// sfml header
#include<SFML/Graphics.hpp>

// own header
#include "Image.h"

class Animation : public Image
{
public:

	Animation(std::string textureFileName, sf::IntRect hitBox, sf::Vector2f position, sf::Vector2i tileSize, int nTilesPerDirection, sf::IntRect rectOfTextureForAnimation);
	~Animation();

	bool moveSprite(int direction, int moveVelocity = 1); //moveVelocity is negative, if the sprite should go backwards
	void resetToFirstAnimationTexture();

private:

	// Sprite:	Bild des (animierten) Objektes. Besitzt eine Position.
	// Texture: Menge aber Bilder, quasi das "Spritesheet" bzw. ein Teil vom Spritesheet.
	// Tile:	Viereck innerhalb einer Textur (nur in Animation relevant)

	int _nTilesPerDirection;	// Anzahl der Vierecke pro Richtung
	sf::Vector2f _tileSize;		// Größe des Vierecks für eine Animationsbewegung (inklusive aller Leeräume)

	float _spriteVelocity;
	sf::IntRect _rectOfSpriteInTexture;

public:

	void setPosition(const sf::Vector2f& position);

};

