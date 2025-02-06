#include "Player.h"

Player::Player()
{
	
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		direction.x -= speed;
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		direction.x += speed;
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		direction.y -= speed;
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		direction.y += speed;
	}
}

void Player::update(float dt)
{
	move(direction * dt);
	direction = sf::Vector2f(0, 0);
}