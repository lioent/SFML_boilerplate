#include "Header/Animation.hpp"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->_totalTime = 0.0f;
	this->_currentImage.x = 0;
	this->_imageCount = imageCount;
	this->_switchTime = switchTime;

	this->_uvRect.width = texture->getSize().x / float(imageCount.x);
	this->_uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime)
{
	_currentImage.y = row;
	_totalTime += deltaTime;

	if (_totalTime >= _switchTime)
	{
		_totalTime -= _switchTime;
		_currentImage.x++;

		if (_currentImage.x >= _imageCount.x)
			_currentImage.x = 0;
	}

	_uvRect.left = _currentImage.x * _uvRect.width;
	_uvRect.top = _currentImage.y * _uvRect.height;
}
