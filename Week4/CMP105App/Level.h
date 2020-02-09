#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <string.h>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Cursor.h"
#include "Background.h"


class Level
{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	void loadTextures();
	void initPlayer();
	void initKoopaEnemy();
	void initGoombaEnemy();
	void initCursor();
	void initBackground();


	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Level objects
	sf::Texture mushTexture;
	sf::Texture goombaTexture;
	sf::Texture koopaTexture;
	sf::Texture cursorIcon;
	sf::Texture backGround;
	Player player_1;
	Enemy goomba_1;
	Enemy koopa_1;
	Cursor customCursor;
	Background bg;
	sf::View view;
};