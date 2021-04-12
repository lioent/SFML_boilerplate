#pragma once
#include "Header/Animation.hpp"
#include "Header/Collider.hpp"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	Player();
	~Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window); // TO DO: move the draw logic to a more specialized class
	void onCollision(sf::Vector2f& direction);

	// GET / SET
	sf::Vector2f position() const
	{
		return this->_body.getPosition();
	}
	Collider collider()
	{
		return Collider(_body);
	}

private:
	sf::RectangleShape _body;
	Animation _animation;
	unsigned int _row;

	float _speed;
	bool _facingRight;

	sf::Vector2f _velocity;
	bool _canJump;
	float _jumpHeight;
};
