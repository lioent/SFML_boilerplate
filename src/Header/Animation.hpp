#pragma once
#include "SFML/Graphics.hpp"

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	Animation();
	~Animation();

	void Update(int row, float deltaTime, bool faceRight);

	// GET / SET
	sf::IntRect uvRect() const
	{
		return this->_uvRect;
	}
	void uvRect(const sf::IntRect uvRect)
	{
		this->_uvRect = uvRect;
	}

private:
	sf::IntRect _uvRect;

	sf::Vector2u _imageCount;
	sf::Vector2u _currentImage;

	float _totalTime;
	float _switchTime;
};
