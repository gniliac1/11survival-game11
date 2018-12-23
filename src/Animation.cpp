#include "pch.h"
#include "Animation.h"

Animation::Animation(sf::IntRect rect) :
	_rectOfSprite(rect)
{

}

Animation::~Animation()
{
}

sf::IntRect Animation::moveSprite(int pressedKey)
{
	if (_rectOfSprite.left == 512) // 8 * 64
	{
		_rectOfSprite.left = 0;
	}
	else
	{
		_rectOfSprite.left += 64;
	}
	switch(pressedKey)
	{
		case sf::Keyboard::Up:
		{
			_rectOfSprite.top = 0; // 0 * 64
			break;
		}
		case sf::Keyboard::Left:
		{
			_rectOfSprite.top = 64; // 1 * 64
			break;
		}
		case sf::Keyboard::Down:
		{
			_rectOfSprite.top = 128; // 2 * 64
			break;
		}
		case sf::Keyboard::Right:
		{
			_rectOfSprite.top = 192; // 3 * 64
			break;
		}
	}
	return _rectOfSprite;
}

void Animation::moveSprite(int pressedKey, std::shared_ptr<sf::Sprite> sprite)
{
	// Position im Sprite Sheet
	sprite->setTextureRect(this->moveSprite(pressedKey));
}

sf::IntRect Animation::getRectOfSprite()
{
	return _rectOfSprite;
}
