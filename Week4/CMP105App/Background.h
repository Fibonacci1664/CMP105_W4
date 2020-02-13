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
	void loadTextures();
	void initBackground();

	sf::Texture backGround;	
};

