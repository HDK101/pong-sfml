#include "CollisionSquare.h"

CollisionSquare::CollisionSquare(){}
void CollisionSquare::SetSquare(sf::IntRect setSquare)
{
	square = setSquare;
}
void CollisionSquare::SetSquarePosition(sf::Vector2f position)
{
	square.left = (int)position.x;
	square.top = (int)position.y;
}
bool CollisionSquare::checkCollision(sf::IntRect squareToCheck)
{
	return square.intersects(squareToCheck);
}
sf::Vector2f CollisionSquare::distanceToSeparate(sf::Vector2f position, sf::IntRect squareToCheck)
{
	SetSquarePosition(position);
	sf::Vector2f temp(0,0);

    int pixelToMoveX = square.width - abs(squareToCheck.left - square.left);
	int pixelToMoveY = square.height - abs(squareToCheck.top - square.top);

	if (square.left > squareToCheck.left)
	{
		temp.x += pixelToMoveX;
	}
	else if (square.left < squareToCheck.left)
	{
		temp.x -= pixelToMoveX;
	}

	if (square.top > squareToCheck.top)
	{
		temp.y += pixelToMoveY;
	}
	else if (square.left < squareToCheck.left)
	{
		temp.y -= pixelToMoveY;
	}
	return temp;
}
sf::IntRect CollisionSquare::getSquare()
{
	return square;
}