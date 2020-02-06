#pragma once
#include "Framework\GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;
	void checkBoundaryCollisions(float dt);

private:
	sf::Vector2f m_increment;
};

