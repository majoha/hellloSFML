#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class player
{
private: const float START_SPEED = 200;
private: const float START_HEALTH = 100;

		 Vector2f m_Position;

		 Sprite m_Sprite;

		 Texture m_Texture;

		 Vector2f m_Resolution;

		 IntRect m_Arena;

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

	Time getLastHitTime();

	bool hit(Time timeHit);
	
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