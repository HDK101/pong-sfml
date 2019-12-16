#ifndef COLLISIONSQUARE_H
#define COLLISIONSQUARE_H

class CollisionSquare
{
	private:
	  sf::IntRect square;
	public:
	  CollisionSquare();
	  bool checkCollision(sf::IntRect squareToCheck);
	  sf::Vector2f distanceToSeparate(sf::Vector2f position, sf::IntRect squareToCheck);
	  void SetSquare(sf::IntRect setSquare);
	  void SetSquarePosition(sf::Vector2f position);
	  sf::IntRect getSquare();
};

#endif