#include "Header/Player.hpp"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	_animation(texture, imageCount, switchTime)
{
	this->_row = 0;
	this->_speed = speed;
	this->_facingRight = true;

	this->_body.setSize(sf::Vector2f(100.0f, 150.0f));
	this->_body.setOrigin(_body.getSize() / 2.0f);
	this->_body.setPosition(206.0f, 206.0f);
	this->_body.setTexture(texture);
}

Player::~Player()
{
}

// Actions
void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= _speed * deltaTime;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += _speed * deltaTime;

	if (movement.x == 0.0f)
		_row = 0;
	else
	{
		_row = 1;
		if (movement.x > 0.0f)
			_facingRight = true;
		else
			_facingRight = false;
	}

	_body.move(movement);
	_animation.Update(_row, deltaTime, _facingRight);
	_body.setTextureRect(_animation.uvRect());
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(_body);
}
