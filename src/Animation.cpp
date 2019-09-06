#include "pch.h"
#include "Animation.h"

//Animation::Animation(std::string textureFileName, sf::IntRect hitBox, sf::Vector2f position, sf::IntRect rectOfAnimationForSprite, sf::IntRect rectOfTextureForAnimation = sf::IntRect())
//	: Image(textureFileName,hitBox,position,rectOfTextureForAnimation)
//{
//	
//	// for Animation instances, the size of the texture is mostly larger than the size of the sprite
//	_sprite->setTextureRect(rectOfAnimationForSprite);
//
//	// set the position of the Animation to a fixed position on screen
//	_sprite->setPosition(position);
//}

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
			_rectOfSprite.top = 512; // 8 * 64
			break;
		}
		case sf::Keyboard::Left:
		{
			_rectOfSprite.top = 576; // 9 * 64
			break;
		}
		case sf::Keyboard::Down:
		{
			_rectOfSprite.top = 640; // 10 * 64
			break;
		}
		case sf::Keyboard::Right:
		{
			_rectOfSprite.top = 704; // 11 * 64
			break;
		}
	}
	return _rectOfSprite;
}

void Animation::reset(std::shared_ptr<sf::Sprite> sprite)
{
	_rectOfSprite.left = 0;
	sprite->setTextureRect(_rectOfSprite);
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

//void Animation::setPosition(const sf::Vector2f & position)
//{
//	_sprite->setPosition(position);
//}
