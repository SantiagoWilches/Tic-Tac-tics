#pragma once
#include "MainBoard.h"

void setFont(sf::Font &font, sf::Text &text);
void quereyPlayers(Player &player, int &playerNumber, bool &play, sf::TcpSocket *&socket);
void updatePlayerString(Player &player, sf::String &playerString, int &playerNumber);
MiniBoardPosition findOpenMiniboard(MainBoard &gameBoard);
int menu(bool &playBool);
void printInstructions();
void playGame(sf::RenderWindow &window, sf::Font &font, int &playerNumber, sf::String &playerString,
	sf::Text &text, Player &player, bool &play, int &servClient, sf::TcpSocket *&socket, sf::Packet &packet);
bool connectMachines(int &servClient, sf::TcpSocket *&mainSocket);
char* vectorToString(sf::Vector2i coordinates);
sf::Vector2i stringToVector(char received[]);