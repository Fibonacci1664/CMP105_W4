#pragma once
#include "Framework\GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	void handleInput(float dt) override;
	void update(float dt) override;
	void move(float dt);

private:
	sf::Vector2f m_increment;
};

