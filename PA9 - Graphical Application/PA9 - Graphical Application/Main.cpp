#include <iostream>
#include "PA9.h"

int main()
{
	Player player;
	sf::Font font;
	sf::Text text;

	sf::String playerString;
	srand((unsigned int)time(NULL));
	int playerNumber = 0;


	sf::RenderWindow window(sf::VideoMode(800, 600), "Test Game", sf::Style::Default);
	printInstructions();
	quereyPlayers(player, playerNumber);
	setFont(font, text);

	playGame(window, font, playerNumber, playerString, text, player);
	system("pause");

	return 0;
}