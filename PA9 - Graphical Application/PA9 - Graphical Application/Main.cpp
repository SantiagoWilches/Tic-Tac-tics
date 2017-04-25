#include "PA9.h"

int main()
{
	Player player;	sf::Font font;	sf::Text text;	sf::String playerString;	int playerNumber = 0;	int servClient = 0;
	int result = 0; sf::TcpSocket *socket;
	srand((unsigned int)time(NULL));
	setFont(font, text);
	bool Connected = false;
	//while (!Connected)
	//{
	//	system("pause");
	//	Connected = connectMachines(servClient, socket);
	//}
	bool play = true;
	while (play)
	{
		result = menu(play);
		if (result == 1)
		{
			if(servClient==0)
				quereyPlayers(player, playerNumber, play, socket);
			if (play)
			{
				sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Tic Tactical", sf::Style::Default);
				playGame(window, font, playerNumber, playerString, text, player, play, servClient);
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