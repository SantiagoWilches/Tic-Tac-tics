#include "MainBoard.h"
/*Default constructor allocates memory for nine miniboards and builds the boards*/
MainBoard::MainBoard()
{
	this->mMainBoard[0][0] = new MiniBoard(sf::Vector2f(175, 100));
	this->mMainBoard[0][1] = new MiniBoard(sf::Vector2f(330, 100));
	this->mMainBoard[0][2] = new MiniBoard(sf::Vector2f(485, 100));
	this->mMainBoard[1][0] = new MiniBoard(sf::Vector2f(175, 255));
	this->mMainBoard[1][1] = new MiniBoard(sf::Vector2f(330, 255));
	this->mMainBoard[1][2] = new MiniBoard(sf::Vector2f(485, 255));
	this->mMainBoard[2][0] = new MiniBoard(sf::Vector2f(175, 410));
	this->mMainBoard[2][1] = new MiniBoard(sf::Vector2f(330, 410));
	this->mMainBoard[2][2] = new MiniBoard(sf::Vector2f(485, 410));
	this->setSize(sf::Vector2f(450, 450));
	this->setFillColor(sf::Color::Green);
	this->setPosition(sf::Vector2f(175, 100));
	this->setOutlineThickness(-12);
}
/*default destructor deletes memory associated with the miniboards.*/
MainBoard::~MainBoard()
{

}
/*getter for miniboard.*/
MiniBoard MainBoard::getMiniBoard(int &row, int&column)
{
	return *(this->mMainBoard[row][column]);
}
/*passes character setting information to from each miniboard into
the miniboard character setting function which passes info to the 
cell character setting function.*/
void MainBoard::setCellCharacter(sf::Vector2i &mousePosition, sf::String &playerString, sf::Font &font, int &playerNumber, MiniBoardPosition &miniPos)
{
	int i = 0, n = 0;
	for (i = 0; i < 3; i++)
	{
		for (n = 0; n < 3; n++)
		{
			this->mMainBoard[i][n]->setCellCharacter(mousePosition, playerString, font, playerNumber, i, n, miniPos);
		}
	}
}
/*draws the mainboard as a cell if it has been won.
Otherwise, the miniboards are drawn one at a time.*/
void MainBoard::draw(sf::RenderWindow &window, sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font, int &playerNumber, MiniBoardPosition &miniPos)
{
	if (this->isWon(mousePosition, newChar, font))
	{
		window.draw(*(dynamic_cast<Cell*>(this)));
		window.draw(this->getCellCharacter());
	}
	else
	{
		int i = 0, n = 0;
		for (i = 0; i < 3; i++)
		{
			for (n = 0; n < 3; n++)
			{
				(this->mMainBoard[i][n])->draw(window, mousePosition, newChar, font, i, n, miniPos);
			}
		}
	}
}
/*determines if mainboard has been won. if it has, cell character is set
by calling the cell version of the setcellcharacter function. 
returns a bool.*/
bool MainBoard::isWon(sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font)
{
	if ((this->mMainBoard[0][0]->isWon(mousePosition, newChar, font)) || 
		(this->mMainBoard[1][1]->isWon(mousePosition, newChar, font)) ||
		(this->mMainBoard[2][2]->isWon(mousePosition, newChar, font)))
	{
		if ((this->mMainBoard[0][0]->isWon(mousePosition, newChar, font))&&
			(!this->mMainBoard[0][0]->getCellCharacter().getString().isEmpty())&&
			((this->mMainBoard[0][0]->getCellCharacter().getString() == this->mMainBoard[0][1]->getCellCharacter().getString()) &&
			(this->mMainBoard[0][2]->getCellCharacter().getString() == this->mMainBoard[0][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}

		else if ((this->mMainBoard[1][0]->isWon(mousePosition, newChar, font)) &&
			(!this->mMainBoard[1][0]->getCellCharacter().getString().isEmpty()) &&
			((this->mMainBoard[1][0]->getCellCharacter().getString() == this->mMainBoard[1][1]->getCellCharacter().getString()) &&
			(this->mMainBoard[1][2]->getCellCharacter().getString() == this->mMainBoard[1][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMainBoard[2][0]->isWon(mousePosition, newChar, font)) &&
			(!this->mMainBoard[2][0]->getCellCharacter().getString().isEmpty()) && 
			((this->mMainBoard[2][0]->getCellCharacter().getString() == this->mMainBoard[2][1]->getCellCharacter().getString()) &&
			(this->mMainBoard[2][2]->getCellCharacter().getString() == this->mMainBoard[2][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMainBoard[0][0]->isWon(mousePosition, newChar, font)) &&
			(!this->mMainBoard[0][0]->getCellCharacter().getString().isEmpty()) && 
			((this->mMainBoard[0][0]->getCellCharacter().getString() == this->mMainBoard[1][0]->getCellCharacter().getString()) &&
			(this->mMainBoard[2][0]->getCellCharacter().getString() == this->mMainBoard[1][0]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMainBoard[0][1]->isWon(mousePosition, newChar, font)) &&
			(!this->mMainBoard[0][1]->getCellCharacter().getString().isEmpty()) && 
			((this->mMainBoard[0][1]->getCellCharacter().getString() == this->mMainBoard[1][1]->getCellCharacter().getString()) &&
			(this->mMainBoard[2][1]->getCellCharacter().getString() == this->mMainBoard[1][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMainBoard[0][2]->isWon(mousePosition, newChar, font)) && 
			(!this->mMainBoard[0][2]->getCellCharacter().getString().isEmpty()) && 
			((this->mMainBoard[0][2]->getCellCharacter().getString() == this->mMainBoard[1][2]->getCellCharacter().getString()) &&
			(this->mMainBoard[2][2]->getCellCharacter().getString() == this->mMainBoard[1][2]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMainBoard[0][0]->isWon(mousePosition, newChar, font)) &&
			(!this->mMainBoard[0][0]->getCellCharacter().getString().isEmpty()) && 
			((this->mMainBoard[0][0]->getCellCharacter().getString() == this->mMainBoard[1][1]->getCellCharacter().getString()) &&
			(this->mMainBoard[2][2]->getCellCharacter().getString() == this->mMainBoard[1][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMainBoard[0][2]->isWon(mousePosition, newChar, font)) &&
			(!this->mMainBoard[0][2]->getCellCharacter().getString().isEmpty()) && 
			((this->mMainBoard[0][2]->getCellCharacter().getString() == this->mMainBoard[1][1]->getCellCharacter().getString()) &&
			(this->mMainBoard[2][0]->getCellCharacter().getString() == this->mMainBoard[1][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMainBoard[0][2]->isClaimed()) && (this->mMainBoard[0][1]->isClaimed()) && (this->mMainBoard[0][0]->isClaimed()) &&
			(this->mMainBoard[1][0]->isClaimed()) && (this->mMainBoard[1][1]->isClaimed()) && (this->mMainBoard[1][2]->isClaimed()) &&
			(this->mMainBoard[2][0]->isClaimed()) && (this->mMainBoard[2][1]->isClaimed()) && (this->mMainBoard[2][2]->isClaimed()))
		{
			sf::String temp = "Draw";
			this->Cell::setCellCharacter(mousePosition, temp, font);
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
/*Clears main board*/
void MainBoard::clearMainBoard(void)
{
	int i = 0, n = 0;
	for (i = 0; i < 3; i++)
	{
		for (n = 0; n < 3; n++)
		{
			this->mMainBoard[i][n]->clearMiniBoard();
		}
	}
}