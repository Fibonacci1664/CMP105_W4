#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	/*
	 * Loading in from here and not the player class, you could
	 * load from the player class for a single player object but
	 * if you had many enemy objects the last thing you would want is
	 * that enemy object having to load its own texture for each and
	 * instance of a created object.
	 */
	mushTexture.loadFromFile("gfx/mushroom_1.png");
	goombaTexture.loadFromFile("gfx/goomba_1.png");

	player_1.setInput(in);
	player_1.setWindow(hwnd);
	player_1.setTexture(&mushTexture);
	player_1.setSize(sf::Vector2f(80, 80));
	player_1.setOrigin(sf::Vector2f(player_1.getSize().x / 2, player_1.getSize().y / 2));
	player_1.setPosition(100, 100);

	goomba_1.setInput(in);
	goomba_1.setWindow(hwnd);
	goomba_1.setTexture(&goombaTexture);
	goomba_1.setSize(sf::Vector2f(100, 100));
	goomba_1.setOrigin(sf::Vector2f(goomba_1.getSize().x / 2, goomba_1.getSize().y / 2));
	goomba_1.setPosition(400, 400);

	goomba_2.setInput(in);
	goomba_2.setWindow(hwnd);
	goomba_2.setTexture(&goombaTexture);
	goomba_2.setSize(sf::Vector2f(100, 100));
	goomba_2.setFillColor(sf::Color::Green);
	goomba_2.setOrigin(sf::Vector2f(goomba_2.getSize().x / 2, goomba_2.getSize().y / 2));
	goomba_2.setPosition(1000, 500);
}

Level::~Level()
{
	std::cout << "Level object destroyed!\n";
}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	// Dealt with level inputs now its time to deal with player inputs.
	player_1.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player_1.update(dt);
	goomba_1.update(dt);
	goomba_2.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(player_1);
	window->draw(goomba_1);
	window->draw(goomba_2);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}