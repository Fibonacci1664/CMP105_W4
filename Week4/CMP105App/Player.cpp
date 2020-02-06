#include "Player.h"

Player::Player()
{
	m_increment = sf::Vector2f(400, 400);
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	// Move left.
	if (input->isKeyDown(sf::Keyboard::A))
	{
		setPosition(sf::Vector2f(getPosition().x - (m_increment.x * dt), getPosition().y));
	}

	// Move right.
	if (input->isKeyDown(sf::Keyboard::D))
	{
		setPosition(sf::Vector2f(getPosition().x + (m_increment.x * dt), getPosition().y));
	}

	// Move up.
	if (input->isKeyDown(sf::Keyboard::W))
	{
		setPosition(sf::Vector2f(getPosition().x, getPosition().y - (m_increment.y * dt)));
	}

	// Move down.
	if (input->isKeyDown(sf::Keyboard::S))
	{
		setPosition(sf::Vector2f(getPosition().x, getPosition().y + (m_increment.y * dt)));
	}
}

void Player::update(float dt)
{
	checkBoundaryCollisions(dt);
}

void Player::checkBoundaryCollisions(float dt)
{
	// If we reach the right hand side of the window.
	if (getPosition().x + getSize().x / 2 > window->getSize().x)
	{
		setPosition(sf::Vector2f(window->getSize().x - getSize().x / 2, getPosition().y));
	}

	// If we reach the left hand side of the window.
	if (getPosition().x - getSize().x / 2 < 0)
	{
		setPosition(sf::Vector2f(0 + getSize().x / 2, getPosition().y));
	}

	// If we reach the bottom of the screen.
	if (getPosition().y + getSize().y / 2 > window->getSize().y)
	{
		setPosition(sf::Vector2f(getPosition().x, window->getSize().y - getSize().y / 2));
	}

	// If we reach the top of the screen.
	if (getPosition().y - getSize().y / 2 < 0)
	{
		setPosition(sf::Vector2f(getPosition().x, 0 + getSize().y / 2));
	}
}
