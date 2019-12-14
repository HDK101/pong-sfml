#ifndef PAD_H
#define PAD_H

#include "CollisionSquare.h"

enum Direction
{
	Up,
	Down,
	Idle
};
enum CurrentPlayer
{
	Player1,
	Player2
};
class Pad
{
private:
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Texture texture;
	std::vector<sf::IntRect> walls;
	CurrentPlayer currentPlayer;
	Direction currentDirection;
	float velocity, maxVelocity, acceleration;
public:
	Pad();
	Pad(sf::Vector2f initialPosition, CurrentPlayer curPlayer);
	sf::Vector2f getSpritePosition();
	sf::Vector2f getPosition();
	float getDistancePoint(sf::Vector2f point);
	void Input();
	void Move();
	void DrawPad();
	void SetPosition(sf::Vector2f pos);
	void SetWalls(std::vector<sf::IntRect> setWalls);
	CollisionSquare collisionSquare;
	sf::Vector2f smoothMove(sf::Vector2f playerPos, sf::Vector2f placeToMove);
	sf::Sprite getSprite();
};

#endif