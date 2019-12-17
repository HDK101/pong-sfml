#include "Ball.h"

Ball::Ball()
{
	position = sf::Vector2f(160, 120);
	sf::IntRect ballRect(0, 0, 8, 8);
	texture.loadFromFile("sprites/ball.png", ballRect);
	collisionSquare.SetSquare(ballRect);
	collisionSquare.SetSquarePosition(sf::Vector2f(160, 120));

	sprite.setTexture(texture);
	sprite.setPosition(position);
	velocity = sf::Vector2f(2, 2);
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
void Ball::Move(sf::Clock &refCollisionCooldown)
{
	sf::Vector2f temp = position;
	position += velocity;
	collisionSquare.SetSquarePosition(position);
	for (auto i = walls.begin(); i != walls.end(); ++i)
	{
		if (collisionSquare.checkCollision(*i))
		{
			PingBall(YAxis);
			position = temp;
			break;
		}
	}
	/*Collision cooldown, then the ball will not get stuck in pads*/
	if (refCollisionCooldown.getElapsedTime().asSeconds() > 1)
	{
		for (auto i = pads.begin(); i != pads.end(); ++i)
		{
			if (collisionSquare.checkCollision(*i))
			{
				PingBall(XAxis);
				position = temp;
				refCollisionCooldown.restart();
				break;
			}
		}
	}
	sprite.setPosition(position);
}
void Ball::PingBall(BallDirection direction)
{
	/*Switch X velocity, when ball hits one of the player pads*/
	if (direction == XAxis)
	{
		velocity.x = -velocity.x;

		/*Generate a float between 0 and 5*/
		int randomY = rand() % 5;
		velocity.y = randomY + 0.5;
	}
	/*Switch Y velocity, when ball hits one of the walls*/
	else if (direction == YAxis)
	{
		velocity.y = -velocity.y;
	}
}