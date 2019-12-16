#include "Ball.h"

Ball::Ball()
{
	position = sf::Vector2f(160, 120);
	sf::IntRect ballRect(0, 0, 8, 8);
	texture.loadFromFile("sprites/ball.png", ballRect);
	collisionSquare.SetSquare(ballRect);
	collisionSquare.SetSquarePosition(sf::Vector2f(160, 120));

	sprite.setTexture(texture);
}
sf::Sprite Ball::getSprite()
{
	return sprite;
}
/*Set pad IntRects for checking collision*/
void Ball::SetPads(std::vector<sf::IntRect> setPads)
{
	pads = setPads;
}
/*Set wall IntRects for checking collision*/
void Ball::SetWalls(std::vector<sf::IntRect> setWalls)
{
	walls = setWalls;
}
void Ball::SetPosition(sf::Vector2f setPosition)
{
	position = setPosition;
}
/*Apply movement per frame*/
void Ball::Move()
{
	collisionSquare.SetSquarePosition(position + velocity);
	for (auto i = walls.begin(); i != walls.end(); ++i)
	{
		if (collisionSquare.checkCollision(*i))
		{
			PingBall(YAxis);
		}
	}
	for (auto i = pads.begin(); i != pads.end(); ++i)
	{
		if (collisionSquare.checkCollision(*i))
		{
			PingBall(XAxis);
		}
	}
}
void Ball::PingBall(BallDirection direction)
{
	/*Switch X velocity, when ball hits one of the player pads*/
	if (direction == XAxis)
	{
		velocity.x = -velocity.x;
	}
	/*Switch Y velocity, when ball hits one of the walls*/
	else if (direction == YAxis)
	{
		velocity.y = -velocity.y;
	}
}