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
	textureBackground.loadFromFile("graphics/sample.png");
	Sprite spriteBackground;
	Sprite spriteBackground1;

	spriteBackground.setTexture(textureBackground);
	spriteBackground1.setTexture(textureBackground);

	
	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}


		spriteBackground.setPosition(0, 0);



		window.clear();
		window.draw(spriteBackground);
		window.draw(spriteBackground1);
		window.display();

	}
	return 0;
}