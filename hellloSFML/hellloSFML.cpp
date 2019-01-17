#include "pch.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "player.h"

using namespace std;
using namespace sf;

int main()
{
	//This is a test
	VideoMode vm(1280, 800);
	RenderWindow window(vm, "Hello, world", Style::Fullscreen);

	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.clear();
		window.draw(spriteBackground);
		window.display();

	}
	return 0;
}