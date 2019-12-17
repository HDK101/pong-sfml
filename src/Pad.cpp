#include "Pad.h"
#include "CollisionSquare.h"

Pad::Pad()
{
	throw "Player and position must be specified!";
}
Pad::Pad(sf::Vector2f initialPosition, CurrentPlayer curPlayer)
{
	position = initialPosition;
	currentPlayer = curPlayer;
	currentDirection = Idle;
	maxVelocity = 15;
	acceleration = 3;
	std::cout << curPlayer << " initialized!";
}
sf::Vector2f Pad::getSpritePosition()
{
	return sprite.getPosition();
}
sf::Vector2f Pad::getPosition()
{
	return position;
}

void Pad::SetPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}
void Pad::SetRealPosition(sf::Vector2f pos)
{
	position = pos;
}
void Pad::SetWalls(std::vector<sf::IntRect> setWalls)
{
	walls = setWalls;
}
float Pad::getDistancePoint(sf::Vector2f point)
{
	return sqrt((position.x - point.x) * (position.x - point.x) + (position.y - point.y) * (position.y - point.y));
}
void Pad::DrawPad()
{
	//Determine Player texture
	if (currentPlayer == Player1)
	{
		texture.loadFromFile("sprites/pad1.png");
	}
	else
	{
		texture.loadFromFile("sprites/pad2.png");
	}

	sf::IntRect square(0, 0, texture.getSize().x, texture.getSize().y);
	collisionSquare.SetSquare(square);

	sprite.setTexture(texture, true);
	sprite.setTextureRect(sf::IntRect(0, 0, 8, 32));

	sprite.setPosition(position);
}
sf::Vector2f Pad::smoothMove(sf::Vector2f playerPos, sf::Vector2f placeToMove)
{
	sf::Vector2f temp = playerPos + placeToMove;
	temp.x /= 2;
	temp.y /= 2;
	return temp;
}
void Pad::Move()
{
	sf::Vector2f tempPosition(0, 0);
	tempPosition = position;

	if (currentDirection == Up)
	{
		position.y -= 5;
	}
	else if (currentDirection == Down)
	{
		position.y += 5;
	}
	for (auto i = walls.begin(); i != walls.end(); ++i)
	{
		collisionSquare.SetSquarePosition(position);
		if (collisionSquare.checkCollision(*i))
		{
			std::cout << "Walls!";
			position = tempPosition;
		}
	}
	SetPosition(smoothMove(getSpritePosition(), getPosition()));
}
void Pad::Input()
{
	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;

	if (currentPlayer == Player1)
	{
		upKey = sf::Keyboard::W;
		downKey = sf::Keyboard::S;
	}
	else
	{
		upKey = sf::Keyboard::Up;
		downKey = sf::Keyboard::Down;
	}

	if (sf::Keyboard::isKeyPressed(upKey))
	{
		currentDirection = Up;
	}
	else if (sf::Keyboard::isKeyPressed(downKey))
	{
		currentDirection = Down;
	}
	else
	{
		currentDirection = Idle;
	}
}
sf::Sprite Pad::getSprite()
{
	return sprite;
}
sf::IntRect Pad::getSquare()
{
	return collisionSquare.getSquare();
}
