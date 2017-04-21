#pragma once
#include "MainBoard.h"

void setFont(sf::Font &font, sf::Text &text);
void quereyPlayers(Player &player, int &playerNumber);
void updatePlayerString(Player &player, sf::String &playerString, int &playerNumber);
MiniBoardPosition findOpenMiniboard(MainBoard &gameBoard);
void printInstructions();