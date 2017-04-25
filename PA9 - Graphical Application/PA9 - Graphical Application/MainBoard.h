#pragma once
#include "MiniBoard.h"
/*Contains 2d array of nine pointers to miniboards*/
class MainBoard :public MiniBoard
{
public:
	MainBoard(void);
	~MainBoard(void);

	void setCellCharacter(sf::Vector2i &mousePosition, sf::String &playerString, sf::Font &font, int &playerNumber, MiniBoardPosition &miniPos);
	void draw(sf::RenderWindow &window, sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font, int &playerNumber, MiniBoardPosition &miniPos);
	bool isWon(sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font);
	MiniBoard getMiniBoard(int &row, int&column);
	void clearMainBoard(void);
private:
	MiniBoard *mMainBoard[3][3];
};