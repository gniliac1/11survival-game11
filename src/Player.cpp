#include "pch.h"
#include "Player.h"


Player::Player()
	: _texture(std::make_unique<sf::Texture>()),
	_sprite(std::make_shared<sf::Sprite>())
{
	if (!_texture->loadFromFile("../graphics/sprites/people/male_walkcycle.png"))
	{
		std::cerr << "Alles kaputt! :(" << std::endl;
	}
	_animation = new Animation();
	_sprite->setTexture(*_texture);

	// set the player to an absolute initial position on the screen
	_sprite->setPosition(sf::Vector2f(480.f, 270.f));
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
		_sprite->move(sf::Vector2f(-2.5, 0.f));
		_animation->moveSprite(sf::Keyboard::Left, _sprite);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// right key is pressed: move our character relative to the current position
		_sprite->move(sf::Vector2f(2.5, 0.f)); 
		_animation->moveSprite(sf::Keyboard::Right, _sprite);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// up key is pressed: move our character relative to the current position
		_sprite->move(sf::Vector2f(0.f, -2.5)); 
		_animation->moveSprite(sf::Keyboard::Up, _sprite);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		// left key is pressed: move our character relative to the current position
		_sprite->move(sf::Vector2f(0.f, 2.5)); 
		_animation->moveSprite(sf::Keyboard::Down, _sprite);
	}
}

std::shared_ptr<sf::Sprite> Player::getSprite()
{
	return _sprite;
}
