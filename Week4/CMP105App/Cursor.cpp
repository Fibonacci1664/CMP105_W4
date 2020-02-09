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
	setPosition(sf::Vector2f(input->getMouseX(), input->getMouseY()));
}