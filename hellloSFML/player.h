#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class player
{
private: const float START_SPEED = 200;
private: const float START_HEALTH = 100;

		 Vector2f m_position;

		 Sprite m_sprite;

		 Texture m_texture;

		 Vector2f m_resolution;

		 IntRect m_arena;

		 int m_TileSize;

		 bool m_UpPressed;
		 bool m_DownPressed;
		 bool m_LeftPressed;
		 bool m_RightPressed;

		 int m_Health;
		 int m_MaxHealth;
		 
		 Time m_LastHit;

		 //speed in pixels per second
		 float m_Speed;

public:
	player();
	void spawn(IntRect arena, Vector2f resolution, int tileSize);
	void resetPlayerStats();

	bool hitTime(Time timeHit);
	
	FloatRect getPosition();

	Vector2f getCenter();

	float getRotation();

	Sprite getSprite();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void stopUp();
	void stopDown();
	void stopLeft();
	void stopRight();

	void update(float elaspedTime, Vector2i mousePosition);

	void upgradeSpeed();
	void upGradeHealth();
	void increaseHealthLevel();

	int getHealth();

};