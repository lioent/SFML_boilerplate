#include "Header/Collider.hpp"

Collider::Collider(sf::RectangleShape& body) :
	_body(body)
{
}

Collider::~Collider()
{
}

// Actions
bool Collider::checkCollision(Collider& collider, sf::Vector2f& direction, float push)
{
	sf::Vector2f colliderPosition = collider.position();
	sf::Vector2f colliderHalfSize = collider.halfSize();
	sf::Vector2f thisPosition = this->position();
	sf::Vector2f thisHalfSize = this->halfSize();

	float deltaX = colliderPosition.x - thisPosition.x;
	float deltaY = colliderPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (colliderHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (colliderHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				move(intersectX * (1.0f - push), 0.0f);
				collider.move(-intersectX * push, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else
			{
				move(-intersectX * (1.0f - push), 0.0f);
				collider.move(intersectX * push, 0.0f);

				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				move(0.0f, intersectY * (1.0f - push));
				collider.move(0.0f, -intersectY * push);

				direction.x = 0.0f;
				direction.y = -1.0f;
			}
			else
			{
				move(0.0f, -intersectY * (1.0f - push));
				collider.move(0.0f, intersectY * push);

				direction.x = 0.0f;
				direction.y = 1.0f;
			}
		}

		return true;
	}

	return false;
}
