#include "PA9.h"

int main()
{
	Player player;	sf::Font font;	sf::Text text;	sf::String playerString;	int playerNumber = 0;	int servClient = 0;
	int result = 0; sf::TcpSocket *socket; sf::Packet packet;
	srand((unsigned int)time(NULL));
	setFont(font, text);
	bool Connected = false;
	while (!Connected)
	{
		system("pause");
		Connected = connectMachines(servClient, socket);
	}
	bool play = true;
	while (play)
	{
		result = menu(play);
		if (result == 1)
		{
			if(servClient==0)
				quereyPlayers(player, playerNumber, play, socket);
			if (servClient == 1)
			{
				char *packetStr; int num;
				socket->receive(packet);
				packet << packetStr;
				if (packetStr[0] == 'x')
				{
					player.playerTwo.insert(0, "x");
					player.playerOne.insert(0, "o");
				}
				else if (packetStr[0] == 'o')
				{
					player.playerTwo.insert(0, "o");
					player.playerOne.insert(0, "x");
				}
				socket->receive(packet);
				packet << num;
				playerNumber = num;
			}
			if (play)
			{
				sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Tic Tactical", sf::Style::Default);
				playGame(window, font, playerNumber, playerString, text, player, play, servClient, socket, packet);
				player.playerOne.clear();
				player.playerTwo.clear();
			}
		}
		if (result == 2)
		{
			printInstructions();
		}
	}
	return 0;
}