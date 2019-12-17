#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Pad.h"

class GameManager
{
private:
	sf::Vector2f &ballPosition;
    int playerOnePoints,playerTwoPoints;
public:
	GameManager();
	int getPlayerOnePoints();
	int getPlayerTwoPoints();
	void Restart();
	void IncreasePoints(CurrentPlayer player);
};
#endif