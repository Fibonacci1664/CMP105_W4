#pragma once
#include "Framework/GameObject.h"

class Background : public GameObject
{
public:
	Background();
	~Background();

	void handleInput(float dt) override;
	void update(float dt) override;

private:
	sf::Vector2f m_increment;
	
};

