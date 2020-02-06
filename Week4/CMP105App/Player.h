#pragma once
#include "Framework/GameObject.h"
#include <SFML/Graphics.hpp>

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;
	sf::Texture mushTexture;

private:
	sf::Vector2f m_increment;
};

