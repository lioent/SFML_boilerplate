#include "Header/Platform.hpp"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	this->_body.setSize(size);
	this->_body.setOrigin(size / 2.0f);
	this->_body.setTexture(texture);
	this->_body.setPosition(position);
}

Platform::Platform()
{
}

Platform::~Platform()
{
}

// Actions
void Platform::draw(sf::RenderWindow& window)
{
	window.draw(_body);
}
