#pragma once
#include "MainBoard.h"

void setFont(sf::Font &font, sf::Text &text);
void quereyPlayers(Player &player, int &playerNumber);
void updatePlayerString(Player &player, sf::String &playerString, int &playerNumber);
MiniBoardPosition findOpenMiniboard(MainBoard &gameBoard);
void printInstructions();
void playGame(sf::RenderWindow &window, sf::Font &font, int &playerNumber, sf::String &playerString, sf::Text &text, Player &player);