#include "pch.h"
#include "player.h"

player::player()
{

	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;

	m_Texture.loadFromFile("graphics/player.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(25, 25);

}

void player::spawn(IntRect arena, Vector2f resolution, int tileSize)
{
	m_Position.x = arena.width / 2;
	m_Position.y = arena.height / 2;

	m_Arena.top = arena.top;
	m_Arena.height = arena.height;
	m_Arena.left = arena.left;
	m_Arena.width = arena.width;

	m_TileSize = tileSize;

	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;
}

void player::update(float elapsedTime, Vector2i mousePosition)
{
	if (m_UpPressed)
	{
		m_Position.y -= m_Speed * elapsedTime;
	}
	else if (m_DownPressed)
	{
		m_Position.y += m_Speed * elapsedTime;
	}
	else if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}
	else if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	m_Sprite.setPosition(m_Position);


	if (m_Position.x > m_Arena.width - m_TileSize)
	{
		m_Position.x = m_Arena.width - m_TileSize;
	}
	else if (m_Position.x < m_Arena.left + m_TileSize)
	{
		m_Position.x = m_Arena.left + m_TileSize;
	}
	else if (m_Position.y > m_Arena.height - m_TileSize)
	{
		m_Position.y = m_Arena.height - m_TileSize;
	}
	else if (m_Position.y < m_Arena.top + m_TileSize)
	{
		m_Position.y = m_Arena.top + m_TileSize;
	}

	float angle = (atan2(mousePosition.y - m_Resolution.y / 2, mousePosition.x - m_Resolution.x / 2 * 180) / 3.141);

	m_Sprite.setRotation(angle);
}

void player::resetPlayerStats()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

Time player::getLastHitTime()
{
	return m_LastHit;
}

bool player::hit(Time timeHit)
{
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)
	{
		m_LastHit = timeHit;
		m_Health -= 10;
		return true;
	}
	else
	{
		return false;
	}
}

FloatRect player::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f player::getCenter()
{
	return m_Position;
}

float player::getRotation()
{
	return m_Sprite.getRotation();
}

Sprite player::getSprite()
{
	return m_Sprite;
}

int player::getHealth()
{
	return m_Health;
}

void player::moveUp()
{
	m_UpPressed = true;
}

void player::moveDown()
{
	m_DownPressed = true;
}

void player::moveLeft()
{
	m_LeftPressed = true;
}

void player::moveRight()
{
	m_RightPressed = true;
}

void player::stopUp()
{
	m_UpPressed = false;
}

void player::stopDown()
{
	m_DownPressed = false;
}

void player::stopLeft()
{
	m_LeftPressed = false;
}

void player::stopRight()
{
	m_RightPressed = false;
}

void player::upgradeSpeed()
{
	m_Speed += (START_SPEED * 0.2);
}

void player::upGradeHealth()
{
	m_Health += (START_HEALTH * 0.2);
}

void player::increaseHealthLevel(int amount)
{
	m_Health += amount;

	if (m_Health > m_MaxHealth)
	{
		m_Health = m_MaxHealth;
	}
}