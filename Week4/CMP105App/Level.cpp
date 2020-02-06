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
	texture.loadFromFile("gfx/mushroom_1.png");

	player_1.setInput(in);
	player_1.setTexture(&texture);
	player_1.setSize(sf::Vector2f(80, 80));
	player_1.setPosition(100, 100);
}

Level::~Level()
{

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
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(testSprite);
	window->draw(player_1);

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