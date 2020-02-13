#include "Background.h"

Background::Background()
{
	loadTextures();
	initBackground();	
}

Background::~Background()
{

}

void Background::handleInput(float dt)
{
	
}

void Background::update(float dt)
{
	
}

void Background::loadTextures()
{
	backGround.loadFromFile("gfx/Level1_1.png");
}

void Background::initBackground()
{
	/*bg.setInput(input);
	bg.setWindow(window);*/
	setTexture(&backGround);
	setSize(sf::Vector2f(11038, 675));
}
