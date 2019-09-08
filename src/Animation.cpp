#include "pch.h"
#include "Animation.h"

Animation::Animation(std::string textureFileName, sf::IntRect hitBox, sf::Vector2f position, sf::Vector2i tileSize, int nTilesPerDirection, sf::IntRect rectOfTextureForAnimation)
	: Image(textureFileName, hitBox, position, rectOfTextureForAnimation),
	_tileSize(tileSize),
	_nTilesPerDirection(nTilesPerDirection)
{
	_rectOfSpriteInTexture = sf::IntRect(0,0,tileSize.x, tileSize.y);
	_sprite->setTextureRect(_rectOfSpriteInTexture);
	_spriteVelocity = 2.5f;
}

Animation::~Animation()
{
}

void Animation::moveSprite(int direction)
{
	if (_rectOfSpriteInTexture.left == (_nTilesPerDirection - 1) * _tileSize.x)
	{
		_rectOfSpriteInTexture.left = 0;
	}
	else
	{
		_rectOfSpriteInTexture.left += _tileSize.x;
	}

	if (_moveDirection.left)
	{
		_sprite->move(direction * _spriteVelocity * sf::Vector2f(-1.f, 0.f));
		_rectOfSpriteInTexture.top = _tileSize.y * 1;
	}
	else if (_moveDirection.right)
	{
		_sprite->move(direction * _spriteVelocity * sf::Vector2f(1.f, 0.f));
		_rectOfSpriteInTexture.top = _tileSize.y * 3;
	}
	else if (_moveDirection.up)
	{
		_sprite->move(direction * _spriteVelocity * sf::Vector2f(0.f, -1.f));
		_rectOfSpriteInTexture.top = _tileSize.y * 0;
	}
	else if (_moveDirection.down)
	{
		_sprite->move(direction * _spriteVelocity * sf::Vector2f(0.f, 1.f));
		_rectOfSpriteInTexture.top = _tileSize.y * 2;
	}
	else // Bewegt sich nicht
	{
		_rectOfSpriteInTexture.left = 0;
	}
	
	_sprite->setTextureRect(_rectOfSpriteInTexture);
	
}

void Animation::setMoveDirection(bool up, bool left, bool down, bool right)
{
	_moveDirection.up = up;
	_moveDirection.left = left;
	_moveDirection.down = down;
	_moveDirection.right = right;
}

void Animation::setPosition(const sf::Vector2f & position)
{
	_sprite->setPosition(position);
}
