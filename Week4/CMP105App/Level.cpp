#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	scrollSpeed = 400;

	hwnd->setMouseCursorVisible(false);

	view = sf::View(sf::FloatRect(0.0f, 0.0f, 1200, 675));
	//view.reset(sf::FloatRect(0.0f, 0.0f, 400, 400));
	// Set its target viewport to be half of the window
	//view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
	window->setView(view);

	loadTextures();
	initPlayer();
	initGoombaEnemy();
	initKoopaEnemy();
	initCursor();
	initBackground();
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

	if (input->isKeyDown(sf::Keyboard::L))
	{
		view.move(scrollSpeed * dt, 0);

		if (view.getCenter().x > (bg.getSize().x - view.getSize().x / 2))
		{
			view.move(-scrollSpeed * dt, 0);
		}
	}

	if (input->isKeyDown(sf::Keyboard::J))
	{
		view.move(-scrollSpeed * dt, 0);

		if (view.getCenter().x < (0 + view.getSize().x / 2))
		{
			view.move(scrollSpeed * dt, 0);
		}
	}

	// Dealt with level inputs now its time to deal with player inputs.
	player_1.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player_1.update(dt);
	goomba_1.update(dt);
	koopa_1.update(dt);
	customCursor.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(bg);
	window->draw(player_1);
	window->draw(goomba_1);
	window->draw(koopa_1);
	window->draw(customCursor);
	window->setView(view);

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

void Level::loadTextures()
{
	/*
	 * Loading in from here and not the player class, you could
	 * load from the player class for a single player object but
	 * if you had many enemy objects the last thing you would want is
	 * that enemy object having to load its own texture for each and
	 * instance of a created object.
	 */
	mushTexture.loadFromFile("gfx/mushroom_1.png");
	goombaTexture.loadFromFile("gfx/goomba_1.png");
	koopaTexture.loadFromFile("gfx/koopa_troopa.png");
	cursorIcon.loadFromFile("gfx/bb_cursor_5.png");
	backGround.loadFromFile("gfx/Level1_1.png");
}

void Level::initPlayer()
{
	player_1.setInput(input);
	player_1.setWindow(window);
	player_1.setTexture(&mushTexture);
	player_1.setSize(sf::Vector2f(80, 80));
	player_1.setOrigin(sf::Vector2f(player_1.getSize().x / 2, player_1.getSize().y / 2));
	player_1.setPosition(100, 100);
}

void Level::initKoopaEnemy()
{
	goomba_1.setInput(input);
	goomba_1.setWindow(window);
	goomba_1.setTexture(&goombaTexture);
	goomba_1.setSize(sf::Vector2f(100, 100));
	goomba_1.setOrigin(sf::Vector2f(goomba_1.getSize().x / 2, goomba_1.getSize().y / 2));
	goomba_1.setPosition(400, 400);
}

void Level::initGoombaEnemy()
{
	koopa_1.setInput(input);
	koopa_1.setWindow(window);
	koopa_1.setTexture(&koopaTexture);
	koopa_1.setSize(sf::Vector2f(100, 100));
	koopa_1.setOrigin(sf::Vector2f(koopa_1.getSize().x / 2, koopa_1.getSize().y / 2));
	koopa_1.setPosition(1000, 500);
}

void Level::initCursor()
{
	customCursor.setInput(input);
	customCursor.setWindow(window);
	customCursor.setTexture(&cursorIcon);
	customCursor.setSize(sf::Vector2f(25, 48));
	//customCursor.setOrigin(sf::Vector2f(customCursor.getSize().x / 2, customCursor.getSize().y / 2));
	//customCursor.setPosition(400, 400);
}

void Level::initBackground()
{
	/*bg.setInput(input);
	bg.setWindow(window);*/
	bg.setTexture(&backGround);
	bg.setSize(sf::Vector2f(11038, 675));
}
