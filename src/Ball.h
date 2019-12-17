#ifndef BALL_H
#define BALL_H

#include "CollisionSquare.h"

enum BallDirection
{
	XAxis,
	YAxis
};

class Ball
{
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Sprite sprite;
	sf::Texture texture;
	std::vector<sf::IntRect> walls;
	std::vector<sf::IntRect> pads;

public:
	Ball();
	CollisionSquare collisionSquare;
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	void SetPads(std::vector<sf::IntRect> setPads);
	void SetWalls(std::vector<sf::IntRect> setWalls);
	void SetPosition(sf::Vector2f setPosition);
	void PingBall(BallDirection direction);
	void Move(sf::Clock &refCollisionCooldown);
};

#endif