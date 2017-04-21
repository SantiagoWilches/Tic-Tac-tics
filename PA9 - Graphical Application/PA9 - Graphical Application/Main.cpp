#include <iostream>
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "PA9.h"

int main()
{
	Player player;
	MainBoard testBoard;
	MiniBoardPosition miniPos, lastPos;
	sf::String playerString;
	srand((unsigned int)time(NULL));
	int playerNumber = 0;
	printInstructions();
	quereyPlayers(player, playerNumber);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Test Game", sf::Style::Default);
	sf::Font font;
	sf::Text text;
	setFont(font, text);

	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2i mousePosition = (sf::Mouse::getPosition() - window.getPosition() - sf::Vector2i(8, 31));
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::EventType::MouseButtonReleased:
				if (testBoard.isWon(mousePosition, playerString, font))
					window.close();
				if (playerNumber == 0) 
				{
					testBoard.setCellCharacter(mousePosition, playerString, font, playerNumber, miniPos);
				}
				else if (playerNumber == 1) 
				{
					testBoard.setCellCharacter(mousePosition, playerString, font, playerNumber, miniPos);
				}
				
				if ((static_cast<Cell>(testBoard.getMiniBoard(miniPos.row, miniPos.column)).isClaimed()) &&
					(static_cast<Cell>(testBoard.getMiniBoard(lastPos.row, lastPos.column)).isClaimed()))
					miniPos = findOpenMiniboard(testBoard);
				else if (static_cast<Cell>(testBoard.getMiniBoard(miniPos.row, miniPos.column)).isClaimed())
					miniPos = lastPos;
				lastPos = miniPos;
				break;
			default:
				break;
			}
		}
		window.clear(sf::Color::Blue);
		text.setString("Test Game");
		window.draw(text);
		testBoard.draw(window, mousePosition, playerString, font, playerNumber, miniPos);
		if (!testBoard.isWon(mousePosition, playerString, font))
			updatePlayerString(player, playerString, playerNumber);
		window.display();
	}

	return 0;
}