#include "Enemy.h"
#include "Player.h"

Enemy::Enemy()
{
	m_increment = sf::Vector2f(400, 400);
}

Enemy::~Enemy()
{

}

void Enemy::handleInput(float dt)
{

}

void Enemy::update(float dt)
{
	move(dt);
}

void Enemy::move(float dt)
{
	if ((getPosition().x + getSize().x / 2 > window->getSize().x && m_increment.x > 0)
		|| (getPosition().x - getSize().x / 2 < 0 && m_increment.x < 0))
	{
		m_increment.x = -m_increment.x;
	}

	if ((getPosition().y + getSize().y / 2 > window->getSize().y && m_increment.y > 0)
		|| (getPosition().y - getSize().y / 2 < 0 && m_increment.y < 0))
	{
		m_increment.y = -m_increment.y;
	}

	// When to specify an sf::Vector and when not to??
	setPosition(sf::Vector2f(getPosition().x + (m_increment.x * dt), getPosition().y + (m_increment.y * dt)));
}