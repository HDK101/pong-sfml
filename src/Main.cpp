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

	/*Texture wall*/
	sf::Texture wall;
	wall.loadFromFile("sprites/walls.png");

	std::vector<sf::IntRect> walls;

	/*Create top wall*/
	sf::IntRect topWallRect(0, 0, 320, 8);
	sf::Sprite topWall(wall, topWallRect);
	walls.push_back(topWallRect);

	/*Create bottom wall*/
	sf::IntRect bottomWallRect(0, 232, 320, 8);
	sf::Sprite bottomWall(wall, bottomWallRect);
	bottomWall.setPosition(0, 232);
	walls.push_back(bottomWallRect);

	/*Create player 1*/
	sf::Vector2f playerOnePos(0, 160);
	Pad playerOnePad(playerOnePos, Player1);
	playerOnePad.SetWalls(walls);
	playerOnePad.DrawPad();

	/*Create player 2*/
	sf::Vector2f playerTwoPos(312, 160);
	Pad playerTwoPad(playerTwoPos, Player2);
	playerTwoPad.SetWalls(walls);
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
		window.draw(topWall);
		window.draw(bottomWall);
		window.display();
	}

	return 0;
}
