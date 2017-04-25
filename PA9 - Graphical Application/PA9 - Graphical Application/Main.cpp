#include "PA9.h"

int main()
{
	Player player;	sf::Font font;	sf::Text text;	sf::String playerString;	int playerNumber = 0;
	srand((unsigned int)time(NULL));
	setFont(font, text);
	printInstructions();
	bool Connected = false;
	while (!Connected)
	{
		system("pause");
		Connected = connectMachines();
	}
	bool play = true;
	while (play)
	{
		quereyPlayers(player, playerNumber, play);
		if (play)
		{
			sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Tic Tactical", sf::Style::Default);
			playGame(window, font, playerNumber, playerString, text, player, play);
			player.playerOne.clear();
			player.playerTwo.clear();
		}
	}
	return 0;
}