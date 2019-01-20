#include "pch.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "ZombieArena.h"
#include "player.h"

using namespace std;
using namespace sf;


int main()
{
	enum class State
	{
		PAUSED, LEVELING_UP, GAME_OVER, PLAYING
	};

	State state = State::GAME_OVER;

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y), "Zombie Arena", Style::Fullscreen);

	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	Clock clock;

	Time gameTimeTotal;

	Vector2f mouseWorldPosition;
	Vector2i mouseScreenPosition;

	player player;

	IntRect arena;

	VertexArray background;

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("graphics/background_sheet.png");

	while (window.isOpen())
	{
		/*
		************
		Handle input
		************
		*/

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return && state == State::PLAYING)
				{
					state = State::PAUSED;
				}
				else if(event.key.code == Keyboard::Return && state == State::PAUSED)
				{
					state = State::PLAYING;
					clock.restart();
				}
				else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
				{
					state = State::LEVELING_UP;
				}
				if (state == State::PLAYING)
				{

				}
			}
		}//end event polling
	
		//Handle player quiting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//handle wsad keyinputs while playing
		if (state == State::PLAYING)
		{
			// Handle the pressing and releasing of the WASD keys
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.moveUp();
			}
			else
			{
				player.stopUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.moveDown();
			}
			else
			{
				player.stopDown();
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.moveLeft();
			}
			else
			{
				player.stopLeft();
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.moveRight();
			}
			else
			{
				player.stopRight();
			}
		}// End WASD while playing

		// Handle the LEVELING up state
		if (state == State::LEVELING_UP)
		{
			// Handle the player LEVELING up
			if (event.key.code == Keyboard::Num1)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num2)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num3)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num4)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num5)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num6)
			{
				state = State::PLAYING;
			}
			if (state == State::PLAYING)
			{
				// Prepare the level
				// We will modify the next two lines later
				arena.width = 500;
				arena.height = 500;
				arena.left = 0;
				arena.top = 0;

				int tileSize = createBackground(background, arena);

				// Spawn the player in the middle of the arena
				player.spawn(arena, resolution, tileSize);
				// Reset the clock so there isn't a frame jump
				clock.restart();
			}
		}// End LEVELING up

		/*
		****************
		End Handle input
		****************
		*/


		/*
		****************
		UPDATE THE FRAME
		****************
		*/

		if (state == State::PLAYING)
		{
			Time dt = clock.restart();

			gameTimeTotal += dt;

			float dtAsSeconds = dt.asSeconds();

			mouseScreenPosition = Mouse::getPosition();

			mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

			player.update(dtAsSeconds, Mouse::getPosition());

			Vector2f playerPosition(player.getCenter());

			mainView.setCenter(player.getCenter());
		}//end updating the scene

		/*
		**************
		Draw the scene
		**************
		*/

		if (state == State::PLAYING)
		{
			window.clear();

			window.setView(mainView);

			window.draw(background, &backgroundTexture);

			window.draw(player.getSprite());

			if (state == State::LEVELING_UP)
			{

			}
			if (state == State::PAUSED)
			{

			}
			if (state == State::GAME_OVER)
			{

			}
			
			window.display();
		}

	}//end game loop

	return 0;
}