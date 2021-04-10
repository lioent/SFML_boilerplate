#pragma once
#include "Header/Animation.hpp"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window); // TO DO: move the draw logic to a more specialized class

	// GET / SET
	sf::Vector2f Position() const
	{
		return this->_body.getPosition();
	}

private:
	sf::RectangleShape _body;
	Animation _animation;
	unsigned int _row;

	float _speed;
	bool _facingRight;
};
