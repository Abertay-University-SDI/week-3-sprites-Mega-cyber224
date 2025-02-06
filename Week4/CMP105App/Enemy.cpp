#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{

}

Enemy::Enemy(sf::Vector2f pos, sf::Vector2f dir, float spd)
{
	setPosition(pos);
	direction = dir;
	speed = spd;
}

void Enemy::update(float dt)
{
	move(direction * (speed * dt));
	if (getPosition().x <= 0)
	{
		setPosition(sf::Vector2f(0, getPosition().y));
		direction.x = 1;
	}
	if (getPosition().x >= window->getSize().x - getSize().x)
	{
		setPosition(sf::Vector2f(window->getSize().x - getSize().x, getPosition().y));
		direction.x = -1;
	}
	if (getPosition().y <= 0)
	{
		setPosition(sf::Vector2f(getPosition().x, 0));
		direction.y = 1;
	}
	if (getPosition().y >= window->getSize().y - getSize().y)
	{
		setPosition(sf::Vector2f(getPosition().x, window->getSize().y - getSize().y));
		direction.y = -1;
	}
}