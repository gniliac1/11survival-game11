#include "pch.h"
#include "Animation.h"
#include "Player.h"

Animation::Animation(std::string textureFileName, sf::IntRect hitBox, sf::Vector2f position, sf::Vector2i tileSize, int nTilesPerDirection, sf::IntRect rectOfTextureForAnimation)
	: Image(textureFileName, hitBox, position, rectOfTextureForAnimation),
	_tileSize(tileSize),
	_nTilesPerDirection(nTilesPerDirection)
{
	_rectOfSpriteInTexture = sf::IntRect(0,0,tileSize.x, tileSize.y);
	_sprite->setTextureRect(_rectOfSpriteInTexture);
	_spriteVelocity = 3.5f;
}

Animation::~Animation()
{
}

/*
	Moves the sprite in one direction with given speed AND choose the next texture.
*/
bool Animation::moveSprite(int direction, int moveVelocity)
{
	if (direction == Player::Direction::LEFT)
	{
		_sprite->move(moveVelocity * _spriteVelocity * sf::Vector2f(-1.f, 0.f));
		_rectOfSpriteInTexture.top = _tileSize.y * 1;
	}
	else if (direction == Player::Direction::RIGHT)
	{
		_sprite->move(moveVelocity * _spriteVelocity * sf::Vector2f(1.f, 0.f));
		_rectOfSpriteInTexture.top = _tileSize.y * 3;
	}
	else if (direction == Player::Direction::UP)
	{
		_sprite->move(moveVelocity * _spriteVelocity * sf::Vector2f(0.f, -1.f));
		_rectOfSpriteInTexture.top = _tileSize.y * 0;
	}
	else if (direction == Player::Direction::DOWN)
	{
		_sprite->move(moveVelocity * _spriteVelocity * sf::Vector2f(0.f, 1.f));
		_rectOfSpriteInTexture.top = _tileSize.y * 2;
	}
	else // Bewegt sich nicht
	{
		_rectOfSpriteInTexture.left = 0;
		//std::cout << "Keine Richtung in Animation::moveSprite()." << std::endl;
		return false;
	}

	if (_rectOfSpriteInTexture.left == (_nTilesPerDirection - 1) * _tileSize.x)
	{
		_rectOfSpriteInTexture.left = 0;
		_sprite->setTextureRect(_rectOfSpriteInTexture);
		return false;
	}
	else
	{
		_rectOfSpriteInTexture.left += _tileSize.x;
		_sprite->setTextureRect(_rectOfSpriteInTexture);
		return true;
	}
}

void Animation::resetToFirstAnimationTexture()
{
	_rectOfSpriteInTexture.left = 0;
	_sprite->setTextureRect(_rectOfSpriteInTexture);
}

void Animation::setPosition(const sf::Vector2f & position)
{
	_sprite->setPosition(position);
}
