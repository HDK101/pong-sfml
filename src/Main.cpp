#include <string>
#include "Main.hpp"
#include "Pad.h"
#include "CollisionSquare.h"
#include "Ball.h"
#include "GameManager.h"

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

	/*Font*/
	sf::Font font;
	font.loadFromFile("font/aldo.ttf");

	/*Scores*/
	sf::Text playerOneScore("0", font, 32u);
	sf::Text playerTwoScore("0", font, 32u);

	playerOneScore.setFillColor(sf::Color::White);
	playerOneScore.setPosition(sf::Vector2f(120, 120));

	playerTwoScore.setFillColor(sf::Color::White);
	playerTwoScore.setPosition(sf::Vector2f(180, 120));

	/*GameManager*/
	GameManager gameManager;

	/*Texture wall*/
	sf::Texture wall;
	wall.loadFromFile("sprites/walls.png");

	std::vector<sf::IntRect> walls;
	std::vector<sf::IntRect> pads;

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
	sf::Vector2f playerOnePos(0, 100);
	Pad playerOnePad(playerOnePos, Player1);
	playerOnePad.SetWalls(walls);
	playerOnePad.DrawPad();

	/*Create player 2*/
	sf::Vector2f playerTwoPos(312, 100);
	Pad playerTwoPad(playerTwoPos, Player2);
	playerTwoPad.SetWalls(walls);
	playerTwoPad.DrawPad();

	/*Ball*/
	sf::Clock ballCollisionClock;
	Ball ball;
	ball.SetWalls(walls);

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
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::R)
				{
					playerOnePad.SetRealPosition(sf::Vector2f(0,100));
					playerTwoPad.SetRealPosition(sf::Vector2f(312,100));
					gameManager.Restart(ball);
				}
			}
		}
		pads.clear();

		playerOnePad.Move();
		playerTwoPad.Move();
		pads.push_back(playerOnePad.getSquare());
		pads.push_back(playerTwoPad.getSquare());
		ball.SetPads(pads);
		ball.Move(ballCollisionClock);
		gameManager.VerifyBall(ball);
		playerOneScore.setString(std::to_string(gameManager.getPlayerPoints(Player1)));
		playerTwoScore.setString(std::to_string(gameManager.getPlayerPoints(Player2)));

		window.clear();
		window.draw(playerOneScore);
		window.draw(playerTwoScore);
		window.draw(playerOnePad.getSprite());
		window.draw(playerTwoPad.getSprite());
		window.draw(topWall);
		window.draw(bottomWall);
		window.draw(ball.getSprite());
		window.display();
	}

	return 0;
}
