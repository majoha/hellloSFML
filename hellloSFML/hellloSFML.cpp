#include "pch.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "player.h"

using namespace std;
using namespace sf;

int main()
{

	int i = 0;

	//This is a test
	VideoMode vm(1280, 800);
	RenderWindow window(vm, "Hello, world", Style::Fullscreen);

	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	
	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}


		spriteBackground.setPosition(i++, 0);



		window.clear();
		window.draw(spriteBackground);
		window.display();

	}
	return 0;
}