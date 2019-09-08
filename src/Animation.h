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

	void moveSprite(int direction = 1);

private:

	// Sprite:	Bild des (animierten) Objektes. Besitzt eine Position.
	// Texture: Menge aber Bilder, quasi das "Spritesheet" bzw. ein Teil vom Spritesheet.
	// Tile:	Viereck innerhalb einer Textur (nur in Animation relevant)

	template<typename T>
	struct DirectionField {
		T up;
		T left;
		T down;
		T right;
	};

	int _nTilesPerDirection;	// Anzahl der Vierecke pro Richtung
	sf::Vector2f _tileSize;		// Größe des Vierecks für eine Animationsbewegung (inklusive aller Leeräume)

	DirectionField<bool> _moveDirection;	// Bewegungsrichtung, mehrere möglich

	float _spriteVelocity;
	sf::IntRect _rectOfSpriteInTexture;

public:

	void setMoveDirection(bool up, bool left, bool down, bool right);
	void setPosition(const sf::Vector2f& position);

};

