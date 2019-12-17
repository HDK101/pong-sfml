#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Pad.h"
#include "Ball.h"

class GameManager
{
private:
	sf::Vector2f ballPosition;
	int playerOnePoints, playerTwoPoints;

public:
	GameManager();
	int getPlayerPoints(CurrentPlayer player);
	void Restart(Ball &ball);
	void IncreasePoints(CurrentPlayer player);
	void VerifyBall(Ball &ball);
};
#endif