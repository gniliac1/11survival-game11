#include "pch.h"
#include "Player.h"


Player::Player(const sf::Vector2f& positionOnScreen)
{
	sf::IntRect hitBox(20, 40, 24, 24);
	sf::Vector2i tileSize(64, 64);
	sf::IntRect rectOfTextureForAnimationMove(0, 64 * 8, 9 * 64, 4 * 64);
	sf::IntRect rectOfTextureForAnimationHit(0, 64 * 4, 8 * 64, 4 * 64);

	_animationMove = std::make_unique<Animation>("../graphics/characters/sander.png", hitBox, positionOnScreen, tileSize, 9, rectOfTextureForAnimationMove);
	_animationHit = std::make_unique<Animation>("../graphics/characters/sander.png", hitBox, positionOnScreen, tileSize, 8, rectOfTextureForAnimationHit);

	_viewingDirection = Direction::LEFT;
}

Player::~Player()
{
}

void Player::move(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_viewingDirection = UP;
		_animationMove->moveSprite(_viewingDirection, elapsedTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_viewingDirection = LEFT;
		_animationMove->moveSprite(_viewingDirection, elapsedTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_viewingDirection = DOWN;
		_animationMove->moveSprite(_viewingDirection, elapsedTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_viewingDirection = RIGHT;
		_animationMove->moveSprite(_viewingDirection, elapsedTime);
	} 
	else
	{
		_animationMove->resetToFirstAnimationTexture();
	}

	_curSprite = _animationMove->getSprite();
	
}

void Player::resetLastMove() 
{
	_animationMove->moveSprite(_viewingDirection,-1);
}

void Player::hit()
{
	if (_hitting)
	{
		_animationHit->setPosition(_animationMove->getPosition());
		_curSprite = _animationHit->getSprite();
		_hitting = _animationHit->moveSprite(_viewingDirection, 0);
	}
}

sf::FloatRect  Player::getBoundingBox()
{
	return _animationMove->getGlobalHitBox();
}

sf::Vector2f Player::getPosition() const
{
	return _curSprite->getPosition();
}

std::shared_ptr<sf::Sprite> Player::getSprite() const
{
	return _curSprite;
}

void Player::setHitting(bool isHitting)
{
	_hitting = isHitting;
}
