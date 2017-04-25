#include "PA9.h"
/*sets the font and other attributes for a sf::Text object.
Imports font information from file and updates sf::Font
object that is passed in.*/
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
/*Prints rules for the game. click anywhere to close screen.*/
void printInstructions()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Welcome", sf::Style::Default);
	sf::Font font;
	sf::Text title, instructions;
	setFont(font, title);
	title.setCharacterSize(60);
	title.setPosition(180, 20);
	setFont(font, instructions);
	instructions.setCharacterSize(28);
	instructions.setFillColor(sf::Color::Black);

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
		instructions.setString("This game is Tic Tac Toe to the extreme. There are nine normal");
		instructions.setPosition(50, 100);
		window.draw(instructions);
		instructions.setString("tic tac toe boards arranged on one giant tic tac toe board. The");
		instructions.setPosition(50, 130);
		window.draw(instructions);
		instructions.setString("object of the game is to win the big board by winning three ""mini""");
		instructions.setPosition(50, 160);
		window.draw(instructions);
		instructions.setString("boards in a row. The game starts in the center ""mini"" board, and");
		instructions.setPosition(50, 190);
		window.draw(instructions);
		instructions.setString("once you select a cell, the other player is forced to play the");
		instructions.setPosition(50, 220);
		window.draw(instructions);
		instructions.setString("""mini"" board that corresponds to that cell's position on the ""mega""");
		instructions.setPosition(50, 250);
		window.draw(instructions);
		instructions.setString("board. If that ""mini"" board has already been won, you will remain");
		instructions.setPosition(50, 280);
		window.draw(instructions);
		instructions.setString("on your current ""mini"" board. If you just won your current board, ");
		instructions.setPosition(50, 310);
		window.draw(instructions);
		instructions.setString("click anywhere, and you will be placed in a random open board.");
		instructions.setPosition(50, 340);
		window.draw(instructions);
		instructions.setString("First player to go will be chosen by the computer at random.");
		instructions.setPosition(50, 370);
		window.draw(instructions);
		instructions.setString("Click anywhere to begin. Good Luck!");
		instructions.setPosition(175, 440);
		window.draw(instructions);
		window.display();
	}
}
/*Asks player one to select "x" or "o". Randomly decides which player
will go first.*/
void quereyPlayers(Player &player, int &playerNumber, bool &play)
{
	Cell *x, *o;
	o = new Cell(sf::Vector2f(380,150)); x = new Cell(sf::Vector2f(200,150));
	sf::Text test, xString, oString, firstPlayer;
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Welcome", sf::Style::Default);
	sf::Font font;
	setFont(font, test);
	setFont(font, oString);
	setFont(font, xString);
	setFont(font, firstPlayer);
	sf::Vector2i mousePosition = (sf::Mouse::getPosition() - window.getPosition() - sf::Vector2i(8, 31));
	x->setSize(sf::Vector2f(140, 140)); o->setSize(sf::Vector2f(140, 140));
	playerNumber = rand() % 2;
	if (playerNumber == 0)
		firstPlayer.setString("Player one will go first.");
	else if (playerNumber == 1)
		firstPlayer.setString("Player two will go first.");
	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2i mousePosition = (sf::Mouse::getPosition() - window.getPosition() - sf::Vector2i(8, 31));
		if ((mousePosition.x > x->getPosition().x) && (mousePosition.y > x->getPosition().y) &&
			(mousePosition.x < (x->getPosition().x + x->getSize().x)) &&
			(mousePosition.y < (x->getPosition().y + x->getSize().y)))
		{
			x->setFillColor(sf::Color::Cyan);
		}
		else
			x->setFillColor(sf::Color::Green);
		if ((mousePosition.x > o->getPosition().x) && (mousePosition.y > o->getPosition().y) &&
			(mousePosition.x < (o->getPosition().x + o->getSize().x)) &&
			(mousePosition.y < (o->getPosition().y + o->getSize().y)))
		{
			o->setFillColor(sf::Color::Cyan);
		}
		else
			o->setFillColor(sf::Color::Green);
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Escape)
				{
					play = false;
					window.close();
				}
			case sf::Event::EventType::MouseButtonReleased:
				if ((mousePosition.x > x->getPosition().x) && (mousePosition.y > x->getPosition().y) &&
					(mousePosition.x < (x->getPosition().x + x->getSize().x)) &&
					(mousePosition.y < (x->getPosition().y + x->getSize().y)))
				{
					player.playerOne.insert(0, "x");
					player.playerTwo.insert(0, "o");
				}
				else if ((mousePosition.x > o->getPosition().x) && (mousePosition.y > o->getPosition().y) &&
					(mousePosition.x < (o->getPosition().x + o->getSize().x)) &&
					(mousePosition.y < (o->getPosition().y + o->getSize().y)))
				{
					player.playerOne.insert(0, "o");
					player.playerTwo.insert(0, "x");
				}
				else if ((mousePosition.x > 0) && (mousePosition.y > 0) &&
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
		test.setPosition(sf::Vector2f(140, 70));
		window.draw(test);
		xString.setPosition(sf::Vector2f(225, 130));
		oString.setPosition(sf::Vector2f(405, 130));
		firstPlayer.setPosition(sf::Vector2f(160, 310));
		xString.setCharacterSize(140);
		oString.setCharacterSize(140);
		x->draw(window);
		o->draw(window);
		window.draw(xString);
		window.draw(oString);
		if (!player.playerOne.isEmpty())
			window.draw(firstPlayer);
		window.display();
	}
}
/*changes whose turn it is. Called from playGame()*/
void updatePlayerString(Player &player, sf::String &playerString, int &playerNumber)
{
	if (playerNumber == 1)
		playerString = player.playerTwo;
	else if (playerNumber == 0)
		playerString = player.playerOne;
}
/*Used to find open miniboard when both the next board
and current board have already been won.*/
MiniBoardPosition findOpenMiniboard(MainBoard &gameBoard)
{
	MiniBoardPosition temp;//Needs work
	int i = 0, n = 0;

	while (gameBoard.getMiniBoard(temp.row, temp.column).isClaimed())
	{
		temp.row = (rand() % 3);
		temp.column = (rand() % 3);
	}
	return temp;
}
/*main game function*/
void playGame(sf::RenderWindow &window, sf::Font &font, int &playerNumber, sf::String &playerString, sf::Text &text, Player &player, bool &play)
{
	MainBoard testBoard;
	MiniBoardPosition miniPos, lastPos;

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
				{
					window.close();
					testBoard.clearMainBoard();
				}
				else if (playerNumber == 0)
				{
					testBoard.setCellCharacter(mousePosition, playerString, font, playerNumber, miniPos);
				}
				else if (playerNumber == 1)
				{
					testBoard.setCellCharacter(mousePosition, playerString, font, playerNumber, miniPos);
				}
				/*checks if current or next miniboard have been won*/
				if ((testBoard.getMiniBoard(miniPos.row, miniPos.column).isClaimed()) &&
					(testBoard.getMiniBoard(lastPos.row, lastPos.column).isClaimed()))
					miniPos = findOpenMiniboard(testBoard);//finds open miniboard at random
				else if (testBoard.getMiniBoard(miniPos.row, miniPos.column).isClaimed())
					miniPos = lastPos;
				lastPos = miniPos;
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Escape) 
				{
					play = false;
					window.close();
				}
			default:
				break;
			}
		}
		window.clear(sf::Color::Blue);
		text.setString("Tic Tactical");
		window.draw(text);
		testBoard.draw(window, mousePosition, playerString, font, playerNumber, miniPos);
		if (!testBoard.isWon(mousePosition, playerString, font))
			updatePlayerString(player, playerString, playerNumber);
		window.display();
	}
}

bool connectMachines()
{
	unsigned short port = 12345;
	char option = '\0';
	std::cout << "Server (s), or Client (c)?" << std::endl;
	std::cin >> option;
	if (option == 's')
	{
		sf::TcpListener listener;

		if (listener.listen(port) != sf::Socket::Done)
			return false;
		std::cout << "Local Address: " << sf::IpAddress::getLocalAddress() << std::endl;
		std::cout << "Server is listening to port " << port << ", waiting for connections... " << std::endl;

		// Wait for a connection
		sf::TcpSocket socket;
		if (listener.accept(socket) != sf::Socket::Done)
			return false;
		std::cout << "Client connected: " << socket.getRemoteAddress() << std::endl;

		// Send a message to the connected client
		const char out[] = "Hi, I'm the server";
		if (socket.send(out, sizeof(out)) != sf::Socket::Done)
			return false;
		std::cout << "Message sent to the client: \"" << out << "\"" << std::endl;

		return true;
	}
	else if (option == 'c')
	{
		sf::IpAddress server;
		do
		{
			std::cout << "Type the address or name of the server to connect to: ";
			std::cin >> server;
		} while (server == sf::IpAddress::None);

		// Create a socket for communicating with the server
		sf::TcpSocket socket;

		// Connect to the server
		if (socket.connect(server, port) != sf::Socket::Done)
			return false;
		std::cout << "Connected to server " << server << std::endl;

		// Receive a message from the server
		char in[128];
		std::size_t received;
		if (socket.receive(in, sizeof(in), received) != sf::Socket::Done)
			return false;
		std::cout << "Message received from the server: \"" << in << "\"" << std::endl;

		// Send an answer to the server
		const char out[] = "Hi, I'm a client";
		if (socket.send(out, sizeof(out)) != sf::Socket::Done)
			return false;
		std::cout << "Message sent to the server: \"" << out << "\"" << std::endl;

		return true;
	}
}