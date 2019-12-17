#include "GameManager.h"

GameManager::GameManager()
{
	playerOnePoints = 0;
	playerTwoPoints = 0;
}
void GameManager::VerifyBall(Ball &ball)
{
	if (ball.getPosition().x < -10)
	{
		IncreasePoints(Player2);
		ball.ResetPosition();
	}
	else if (ball.getPosition().x > 330)
	{
		IncreasePoints(Player1);
		ball.ResetPosition();
	}
}
void GameManager::IncreasePoints(CurrentPlayer player)
{
	if (player == Player1)
	{
		playerOnePoints++;
		std::cout << "Increased points for Player 1!";
	}
	else if (player == Player2)
	{
		playerTwoPoints++;
		std::cout << "Increased points for Player 2!";
	}
}
int GameManager::getPlayerPoints(CurrentPlayer player)
{
	/*If "player" is Player1, then return playerOnePoints, else return playerTwoPoints*/
	return player == Player1 ? playerOnePoints : playerTwoPoints;
}