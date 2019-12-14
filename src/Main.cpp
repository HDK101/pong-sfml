#include "Main.hpp"
#include "Pad.h"
#include "CollisionSquare.h"

int main()
{
#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window(sf::VideoMode(320, 240), "SFML works!");
#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	sf::Event event;
	sf::Clock clock, delta;

	sf::Vector2f playerOnePos(5, 5);
	Pad playerOnePad(playerOnePos, Player1);
	playerOnePad.DrawPad();

	sf::Vector2f playerTwoPos(315, 5);
	Pad playerTwoPad(playerTwoPos, Player2);
	playerTwoPad.DrawPad();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			playerOnePad.Input();
			playerTwoPad.Input();
			delta.restart();
		}
		playerOnePad.Move();
		playerTwoPad.Move();

		window.clear();
		window.draw(playerOnePad.getSprite());
		window.draw(playerTwoPad.getSprite());
		window.display();
	}

	return 0;
}
