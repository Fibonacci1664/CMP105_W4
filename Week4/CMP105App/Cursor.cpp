#include "Cursor.h"

Cursor::Cursor()
{

}

Cursor::~Cursor()
{

}

void Cursor::handleInput(float dt)
{

}

void Cursor::update(float dt)
{

}

void Cursor::update(float dt, sf::View& view)
{
	setPosition(sf::Vector2f(input->getMouseX() + (view.getCenter().x - view.getSize().x / 2.0f), input->getMouseY()));
}