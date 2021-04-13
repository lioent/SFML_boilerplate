#include "Header/Player.hpp"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	_animation(texture, imageCount, switchTime)
{
	this->_row = 0;
	this->_speed = speed;
	this->_facingRight = true;
	this->_jumpHeight = jumpHeight;
	this->_velocity = sf::Vector2f(0.0f, 0.0f);

	this->_body.setSize(sf::Vector2f(100.0f, 150.0f));
	this->_body.setOrigin(_body.getSize() / 2.0f);
	this->_body.setPosition(206.0f, 206.0f);
	this->_body.setTexture(texture);
}

Player::Player()
{
}

Player::~Player()
{
}

// Actions
void Player::update(float deltaTime)
{
	_velocity.x *= 0.5f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		_velocity.x -= _speed;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		_velocity.x += _speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _canJump)
	{
		_canJump = false;
		_velocity.y = -sqrtf(2.0f * 981.0f * _jumpHeight);
	}

	_velocity.y += 981.0f * deltaTime;

	if (_velocity.x == 0.0f)
		_row = 0;
	else
	{
		_row = 1;
		if (_velocity.x > 0.0f)
			_facingRight = true;
		else
			_facingRight = false;
	}

	_animation.Update(_row, deltaTime, _facingRight);
	_body.setTextureRect(_animation.uvRect());
	_body.move(_velocity * deltaTime);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(_body);
}

void Player::onCollision(sf::Vector2f& direction)
{
	if (direction.x < 0.0f)
	{
		// collision on the left
		_velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		// collision on the left
		_velocity.x = 0.0f;
	}

	std::cout << direction.y << std::endl;
	std::cout << _velocity.y << std::endl;
	if (direction.y > 0.0f)
	{
		_velocity.y = 0.0f;
		_canJump = true;
	}
	else if (direction.y < 0.0f)
	{
		_velocity.y = 0.0f;
	}
}
