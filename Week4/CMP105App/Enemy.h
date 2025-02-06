#pragma once
#include "Framework/GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(sf::Vector2f pos, sf::Vector2f dir, float spd);
	void update(float dt) override;

private:
	sf::Vector2f direction = sf::Vector2f(1, 1);
	float speed = 500;
};

