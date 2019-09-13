#include "pch.h"
#include "Player.h"


Player::Player()
{
	//sf::IntRect test(left, top, width, height);
	sf::IntRect hitBox(20, 40, 24, 24);
	sf::IntRect rectOfTextureForAnimationMove(0, 64 * 8, 9 * 64, 4 * 64);
	sf::IntRect rectOfTextureForAnimationHit(0, 64 * 4, 8 * 64, 4 * 64);
	_animationMove = new Animation("../graphics/characters/sander.png", hitBox, sf::Vector2f(1800.f, 500.f), sf::Vector2i(64, 64), 9, rectOfTextureForAnimationMove);
	_animationHit = new Animation("../graphics/characters/sander.png", hitBox, sf::Vector2f(1800.f, 500.f), sf::Vector2i(64, 64), 8, rectOfTextureForAnimationHit);

	_viewingDirection = Direction::LEFT;
}


Player::~Player()
{
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_viewingDirection = UP;
		_animationMove->moveSprite(_viewingDirection);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_viewingDirection = LEFT;
		_animationMove->moveSprite(_viewingDirection);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_viewingDirection = DOWN;
		_animationMove->moveSprite(_viewingDirection);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_viewingDirection = RIGHT;
		_animationMove->moveSprite(_viewingDirection);
	}

	_curSprite = _animationMove->getSprite();
	
}

void Player::resetLastMove() 
{
	_animationMove->moveSprite(-1);
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

std::shared_ptr<sf::Sprite> Player::getSprite() const
{
	return _curSprite;
}

void Player::setHitting(bool isHitting)
{
	_hitting = isHitting;
}
