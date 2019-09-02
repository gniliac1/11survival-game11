#include "pch.h"
#include "Image.h"


Image::Image(std::string textureFileName, sf::IntRect hitBox, sf::Vector2f position, sf::IntRect rectOfTextureForSprite=sf::IntRect())
	: _hitBox(hitBox),
	_sprite(std::make_shared<sf::Sprite>()),
	_texture(std::make_unique<sf::Texture>())
{
	// load the texture from the provided filename
	if (!_texture->loadFromFile(textureFileName, rectOfTextureForSprite))
	{
		std::cerr << "Error in Image.h:" << std::endl 
			<< "Unable to load texture from file " << textureFileName << std::endl;
	}

	// for Image instances, the size of the texture always corresponds to the size of the sprite
	_sprite->setTexture(*_texture);

	// set the position of the Image to a fixed position on screen
	_sprite->setPosition(position);
}

Image::~Image()
{
}

sf::FloatRect Image::getGlobalHitBox() const
{
	// compute the hit box of the image in global coordinates
	sf::FloatRect boundingBox = _sprite->getGlobalBounds();
	boundingBox.width = _hitBox.width;
	boundingBox.height = _hitBox.height;
	boundingBox.top += _hitBox.top;
	boundingBox.left += _hitBox.left;
	return boundingBox;
}

sf::Vector2f Image::getPosition() const
{
	return _sprite->getPosition();
}

std::shared_ptr<sf::Sprite> Image::getSprite() const
{
	return _sprite;
}

//void Image::setPosition(const sf::Vector2f& position)
//{
//	_sprite->setPosition(position);
//}