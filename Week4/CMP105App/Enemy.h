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

	inline
		// Set the window component.
		// WHY DO THIS ONLY WORK WINDOW AND NOT RENDERWINDOW??
		// WE GET OVERRIDE ERROR.
		void setWindow(sf::Window* hwnd) { window = hwnd; }

private:
	sf::Vector2f m_increment;

	// Window component.
	// WHY DO THIS ONLY WORK WINDOW AND NOT RENDERWINDOW??
	// WE GET OVERRIDE ERROR.
	sf::Window* window;
};

