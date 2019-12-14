#include <catch2/catch.hpp>
#include <math.h>

// This example is a bit silly, but you get the idea
TEST_CASE("sf::RenderWindow", "[renderwindow]")
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	REQUIRE(window.getSize().x == 200);
	REQUIRE(window.getSize().y == 200);

	sf::CircleShape shape(window.getSize().x / 2);
	shape.setFillColor(sf::Color::White);

	REQUIRE(shape.getRadius() == 100.0f);
	REQUIRE(shape.getFillColor() == sf::Color::White);
	REQUIRE(static_cast<int>(shape.getLocalBounds().width) == 198); // 🤔
	REQUIRE(static_cast<int>(shape.getLocalBounds().height) == 200);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);

	REQUIRE(shapeTexture.getSize().x == 256);
	REQUIRE(shapeTexture.getSize().y == 256);
	REQUIRE(shape.getTexture() == &shapeTexture);

	sf::IntRect r1(0, 2, 20, 5);
	sf::IntRect r2(19, 0, 20, 5);

	int pixelToMoveX = r1.width - abs(r2.left - r1.left);
	int pixelToMoveY = r1.height - abs(r2.top - r1.top);

	bool b3 = r1.intersects(r2);

	REQUIRE(b3 == true);
	REQUIRE(pixelToMoveX == 1);
	REQUIRE(pixelToMoveY == 3);

	if (r1.left > r2.left)
	{
		r1.left += pixelToMoveX;
	}
	else if (r1.left < r2.left)
	{
		r1.left -= pixelToMoveX;
	}

	if (r1.top > r2.top)
	{
		r1.top += pixelToMoveY;
	}
	else if (r1.left < r2.left)
	{
		r1.top -= pixelToMoveY;
	}

	b3 = r1.intersects(r2);
	REQUIRE(b3 == false);

	// Show the RenderWindow once
	window.clear();
	window.draw(shape);
	window.display();

	REQUIRE(window.isOpen() == true);
}