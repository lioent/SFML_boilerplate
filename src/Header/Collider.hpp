#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);
	Collider();
	~Collider();

	// Actions
	void move(float dx, float dy)
	{
		this->_body.move(dx, dy);
	}

	bool checkCollision(Collider& collider, sf::Vector2f& direction, float push);

	// GET / SET
	sf::Vector2f position() const
	{
		return this->_body.getPosition();
	}
	sf::Vector2f halfSize() const
	{
		return this->_body.getSize() / 2.0f;
	}

private:
	sf::RectangleShape& _body;
};
