#pragma once
#include "Framework\GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;
	void update(float dt, sf::View& view);
	void checkBoundaryCollisions(float dt, sf::View& view);

private:
	sf::Vector2f m_increment;
};

