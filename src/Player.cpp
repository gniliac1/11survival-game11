#include "pch.h"
#include "Player.h"


Player::Player()
{
	sf::IntRect hitBox(20, 40, 24, 24);
	sf::IntRect rectOfTextureForAnimation(0, 64 * 8, 9 * 64, 4 * 64);
	_animation = new Animation("../graphics/characters/sander.png", hitBox, sf::Vector2f(1800.f, 500.f), sf::Vector2i(64, 64), 9, rectOfTextureForAnimation);
}


Player::~Player()
{
}

void Player::move()
{
	_animation->setMoveDirection(sf::Keyboard::isKeyPressed(sf::Keyboard::Up), 
								 sf::Keyboard::isKeyPressed(sf::Keyboard::Left), 
								 sf::Keyboard::isKeyPressed(sf::Keyboard::Down), 
								 sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
	_animation->moveSprite();
}

void Player::resetLastMove() 
{
	_animation->moveSprite(-1);
}

sf::FloatRect  Player::getBoundingBox()
{
	return _animation->getGlobalHitBox();
}

std::shared_ptr<sf::Sprite> Player::getSprite() const
{
	return _animation->getSprite();
}