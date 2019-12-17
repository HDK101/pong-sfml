#include "GameManager.h"

void GameManager::VerifyBall(Ball &ball)
{
	if (ball.getPosition().x < -10)
	{
		IncreasePoints(Player2);
		ball.SetPosition(sf::Vector2f(160,120));
	}
	else if (ball.getPosition().x > 330)
	{
		IncreasePoints(Player1);
		ball.SetPosition(sf::Vector2f(160,120));
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