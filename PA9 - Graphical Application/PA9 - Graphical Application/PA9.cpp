#include "PA9.h"

void setFont(sf::Font &font, sf::Text &text)
{
	if (!font.loadFromFile("DK Knucklebones.otf"))
	{
		std::cout << "Failed to load font from file" << std::endl;
	}
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Magenta);
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
	text.setPosition(sf::Vector2f(325, 25));
}

void printInstructions()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Welcome", sf::Style::Default);
	sf::Font font;
	sf::Text title, instructions;
	setFont(font, title);
	title.setCharacterSize(60);
	title.setPosition(180, 25);
	setFont(font, instructions);
	instructions.setCharacterSize(25);


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
				if ((mousePosition.x > 0) && (mousePosition.y > 0) &&
					(mousePosition.x < window.getSize().x) && (mousePosition.y < window.getSize().y))
					window.close();
				break;
			default:
				break;
			}
		}
		window.clear(sf::Color::Blue);
		title.setString("Super Tic Tac Toe");
		window.draw(title);
		instructions.setString("This game is Tic Tac Toe to the extreme. There are nine normal tic");
		instructions.setPosition(60, 100);
		window.draw(instructions);
		instructions.setString("tac toe boards arranged on one giant tic tac toe board. The object");
		instructions.setPosition(60, 130);
		window.draw(instructions);
		instructions.setString("of the game is to win the big board by winning three ""mini"" boards ");
		instructions.setPosition(60, 160);
		window.draw(instructions);
		instructions.setString("in a row. The game starts in the center ""mini"" board, and once you");
		instructions.setPosition(60, 190);
		window.draw(instructions);
		instructions.setString("select a cell, the other player is forced to play the ""mini"" board");
		instructions.setPosition(60, 220);
		window.draw(instructions);
		instructions.setString("that corresponds to that cell's position on the ""mega"" board. If that");
		instructions.setPosition(60, 250);
		window.draw(instructions);
		instructions.setString("""mini"" board has already been won, you will remain on your current");
		instructions.setPosition(60, 280);
		window.draw(instructions);
		instructions.setString("""mini"" board. If you just won your current board, click anywhere, and");
		instructions.setPosition(60, 310);
		window.draw(instructions);
		instructions.setString("you will be placed on the first open board.");
		instructions.setPosition(60, 340);
		window.draw(instructions);
		instructions.setString("Click anywhere to begin. Good Luck!");
		instructions.setPosition(180, 390);
		window.draw(instructions);
		window.display();
	}
}

void quereyPlayers(Player &player, int &playerNumber)
{
	Cell *x, *o;
	o = new Cell; x = new Cell;
	sf::Text test, xString, oString;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Welcome", sf::Style::Default);
	sf::Font font;
	setFont(font, test);
	setFont(font, oString);
	setFont(font, xString);
	sf::Vector2i mousePosition = (sf::Mouse::getPosition() - window.getPosition() - sf::Vector2i(8, 31));

	x->setSize(sf::Vector2f(140, 140)); o->setSize(sf::Vector2f(140, 140));

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
				if ((mousePosition.x > 0) && (mousePosition.y > 0) &&
					(mousePosition.x < window.getSize().x) && (mousePosition.y < window.getSize().y))
					window.close();
				break;
			default:
				break;
			}
		}
		window.clear(sf::Color::Blue);
		test.setString("Player 1, Select your weapon.");
		oString.setString("o");
		xString.setString("x");
		window.draw(test);
		o->setPosition(200, 100);
		x->setPosition(380, 100);
		xString.setPosition(sf::Vector2f(200, 100));
		oString.setPosition(sf::Vector2f(380, 100));
		x->draw(window);
		o->draw(window);
		window.draw(xString);
		window.draw(oString);
		window.display();
	}

	string str;
	cout << "Enter a character to represent player 1 cells." << endl;
	cin >> str;
	player.playerOne.insert(0, str);
	cout << "Enter a character to represent player 2 cells." << endl;
	cin >> str;
	player.playerTwo.insert(0, str);
	playerNumber = (rand() % 2);
	cout << "Player: " << (playerNumber + 1) << " Will Go First." << endl;
	system("pause");
}

void updatePlayerString(Player &player, sf::String &playerString, int &playerNumber)
{
	if (playerNumber == 1)
		playerString = player.playerTwo;
	else if (playerNumber == 0)
		playerString = player.playerOne;
}

MiniBoardPosition findOpenMiniboard(MainBoard &gameBoard)
{
	MiniBoardPosition temp;
	int i = 0, n = 0;

	for (i = 0; i < 3; i++) 
	{
		for (n = 0; n < 3; n++)
		{
			if (!gameBoard.getMiniBoard(i, n).isClaimed())
			{
				temp.row = i;
				temp.column = n;
				return temp;
			}
		}
	}
}