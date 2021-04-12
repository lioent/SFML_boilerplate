#pragma once
#include "Header/Collider.hpp"

class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	Platform();
	~Platform();

	void draw(sf::RenderWindow& window);

	// GET / SET
	Collider collider()
	{
		return Collider(_body);
	}

private:
	sf::RectangleShape _body;
};
