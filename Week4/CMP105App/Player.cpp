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
	
}