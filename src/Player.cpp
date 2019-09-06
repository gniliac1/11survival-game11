#include "pch.h"
#include "Player.h"


Player::Player()
	: _texture(std::make_unique<sf::Texture>()),
	_sprite(std::make_shared<sf::Sprite>()),
	_lastMovement(0.0f,0.0f),
	_velocity(2.5f)
{
	if (!_texture->loadFromFile("../graphics/characters/sander.png"))
	{
		std::cerr << "Alles kaputt! :(" << std::endl;
	}
	_animation = new Animation();
	_sprite->setTexture(*_texture);

	// set the player to an absolute initial position on the screen
	_sprite->setPosition(sf::Vector2f(1800.f, 500.f));
	// choose the right ractangle of the sprite sheet
	_sprite->setTextureRect(_animation->getRectOfSprite());
}


Player::~Player()
{
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// left key is pressed: move our character relative to the current position
		_lastMovement = _velocity * sf::Vector2f(-1.f, 0.f);
		_sprite->move(_lastMovement);
		_animation->moveSprite(sf::Keyboard::Left, _sprite);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// right key is pressed: move our character relative to the current position
		_lastMovement = _velocity * sf::Vector2f(1.f, 0.f);
		_sprite->move(_lastMovement);
		_animation->moveSprite(sf::Keyboard::Right, _sprite);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// up key is pressed: move our character relative to the current position
		_lastMovement = _velocity * sf::Vector2f(0.f, -1.f);
		_sprite->move(_lastMovement);
		_animation->moveSprite(sf::Keyboard::Up, _sprite);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		// left key is pressed: move our character relative to the current position
		_lastMovement = _velocity * sf::Vector2f(0.f, 1.f);
		_sprite->move(_lastMovement);
		_animation->moveSprite(sf::Keyboard::Down, _sprite);
	}
	else {
		_animation->reset(_sprite);
	}
}

void Player::resetLastMove() 
{
	_sprite->move(-1.f*_lastMovement);
}

sf::FloatRect  Player::getBoundingBox()
{
	sf::FloatRect boundingBox = _sprite->getGlobalBounds();
	boundingBox.width = 24;
	boundingBox.height = 24;
	boundingBox.top += 40;
	boundingBox.left += 20;
	return boundingBox;
}

std::shared_ptr<sf::Sprite> Player::getSprite()
{
	return _sprite;
}
