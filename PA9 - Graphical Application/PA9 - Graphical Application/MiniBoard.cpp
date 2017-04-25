#include "MiniBoard.h"
/*This constructor is not defined but must be declared*/
MiniBoard::MiniBoard(void)
{

}
/*destructor deletes dynamically allocated memory associated
with the nine cell pointers in the miniboard*/
MiniBoard::~MiniBoard(void)
{

}
/*This miniboard constructor accepts a coordinate for the origin of the
miniboard. that position is used to build the cells in the miniboard*/
MiniBoard::MiniBoard(sf::Vector2f &position)
{
	this->mMiniBoardArray[0][0] = new Cell(position);
	this->mMiniBoardArray[0][1] = new Cell(position + sf::Vector2f(50, 0));
	this->mMiniBoardArray[0][2] = new Cell(position + sf::Vector2f(100, 0));
	this->mMiniBoardArray[1][0] = new Cell(position + sf::Vector2f(0, 50));
	this->mMiniBoardArray[1][1] = new Cell(position + sf::Vector2f(50, 50));
	this->mMiniBoardArray[1][2] = new Cell(position + sf::Vector2f(100, 50));
	this->mMiniBoardArray[2][0] = new Cell(position + sf::Vector2f(0, 100));
	this->mMiniBoardArray[2][1] = new Cell(position + sf::Vector2f(50, 100));
	this->mMiniBoardArray[2][2] = new Cell(position + sf::Vector2f(100, 100));
	this->setSize(sf::Vector2f(140, 140));
	this->setFillColor(sf::Color::Green);
	this->setPosition(position);
	this->setOutlineThickness(-8);
}
/*used to cycle through cells in a miniboard before passing the cell
info to the cell version of this function for actual character setting.*/
void MiniBoard::setCellCharacter(sf::Vector2i &mousePosition, sf::String &playerString, sf::Font &font, int &playerNumber, int &p, int &q, MiniBoardPosition &miniPos)
{
	int i = 0, n = 0;
	for (i = 0; i < 3; i++)
	{
		for (n = 0; n < 3; n++)
		{
			this->mMiniBoardArray[i][n]->setCellCharacter(i, n, mousePosition, playerString, font, playerNumber, p, q, miniPos);
		}
	}
}
/*Draws miniboard as cell if it has been won. Otherwise it calls
the cell draw function for each member cell.*/
void MiniBoard::draw(sf::RenderWindow &window, sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font, int &p, int &q, MiniBoardPosition &miniPos)
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
				this->mMiniBoardArray[i][n]->draw(window, mousePosition, p, q, miniPos);
			}
		}
	}
}
/*uses brute force logic to determine if miniboard has been won.
If miniboard has been won, calls cell version of setCellCharacter
to set the miniboard character to the winner's character.
Returns a bool.*/
bool MiniBoard::isWon(sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font)
{
	if ((this->mMiniBoardArray[0][0]->isClaimed())||(this->mMiniBoardArray[1][1]->isClaimed())||(this->mMiniBoardArray[2][2]->isClaimed()))
	{
		if ((this->mMiniBoardArray[0][0]->isClaimed()) && (!this->mMiniBoardArray[0][0]->getCellCharacter().getString().isEmpty()) && ((this->mMiniBoardArray[0][0]->getCellCharacter().getString() == this->mMiniBoardArray[0][1]->getCellCharacter().getString()) &&
			(this->mMiniBoardArray[0][2]->getCellCharacter().getString() == this->mMiniBoardArray[0][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}

		else if ((this->mMiniBoardArray[1][0]->isClaimed()) && (!this->mMiniBoardArray[1][0]->getCellCharacter().getString().isEmpty()) && ((this->mMiniBoardArray[1][0]->getCellCharacter().getString() == this->mMiniBoardArray[1][1]->getCellCharacter().getString()) &&
			(this->mMiniBoardArray[1][2]->getCellCharacter().getString() == this->mMiniBoardArray[1][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMiniBoardArray[2][0]->isClaimed()) && (!this->mMiniBoardArray[2][0]->getCellCharacter().getString().isEmpty()) && ((this->mMiniBoardArray[2][0]->getCellCharacter().getString() == this->mMiniBoardArray[2][1]->getCellCharacter().getString()) &&
			(this->mMiniBoardArray[2][2]->getCellCharacter().getString() == this->mMiniBoardArray[2][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMiniBoardArray[0][0]->isClaimed()) && (!this->mMiniBoardArray[0][0]->getCellCharacter().getString().isEmpty()) && ((this->mMiniBoardArray[0][0]->getCellCharacter().getString() == this->mMiniBoardArray[1][0]->getCellCharacter().getString()) &&
			(this->mMiniBoardArray[2][0]->getCellCharacter().getString() == this->mMiniBoardArray[1][0]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMiniBoardArray[0][1]->isClaimed()) && (!this->mMiniBoardArray[0][1]->getCellCharacter().getString().isEmpty()) && ((this->mMiniBoardArray[0][1]->getCellCharacter().getString() == this->mMiniBoardArray[1][1]->getCellCharacter().getString()) &&
			(this->mMiniBoardArray[2][1]->getCellCharacter().getString() == this->mMiniBoardArray[1][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMiniBoardArray[0][2]->isClaimed()) && (!this->mMiniBoardArray[0][2]->getCellCharacter().getString().isEmpty()) && ((this->mMiniBoardArray[0][2]->getCellCharacter().getString() == this->mMiniBoardArray[1][2]->getCellCharacter().getString()) &&
			(this->mMiniBoardArray[2][2]->getCellCharacter().getString() == this->mMiniBoardArray[1][2]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMiniBoardArray[0][0]->isClaimed()) && (!this->mMiniBoardArray[0][0]->getCellCharacter().getString().isEmpty()) && ((this->mMiniBoardArray[0][0]->getCellCharacter().getString() == this->mMiniBoardArray[1][1]->getCellCharacter().getString()) &&
			(this->mMiniBoardArray[2][2]->getCellCharacter().getString() == this->mMiniBoardArray[1][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMiniBoardArray[0][2]->isClaimed()) && (!this->mMiniBoardArray[0][2]->getCellCharacter().getString().isEmpty()) && ((this->mMiniBoardArray[0][2]->getCellCharacter().getString() == this->mMiniBoardArray[1][1]->getCellCharacter().getString()) &&
			(this->mMiniBoardArray[2][0]->getCellCharacter().getString() == this->mMiniBoardArray[1][1]->getCellCharacter().getString())))
		{
			this->Cell::setCellCharacter(mousePosition, newChar, font);
			return true;
		}
		else if ((this->mMiniBoardArray[0][2]->isClaimed()) && (this->mMiniBoardArray[0][1]->isClaimed()) && (this->mMiniBoardArray[0][0]->isClaimed()) &&
			(this->mMiniBoardArray[1][0]->isClaimed()) && (this->mMiniBoardArray[1][1]->isClaimed()) && (this->mMiniBoardArray[1][2]->isClaimed()) &&
			(this->mMiniBoardArray[2][0]->isClaimed()) && (this->mMiniBoardArray[2][1]->isClaimed()) && (this->mMiniBoardArray[2][2]->isClaimed())) {
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
/*Clears miniboard*/
void MiniBoard::clearMiniBoard(void)
{
	int i = 0, n = 0;
	for (i = 0; i < 3; i++)
	{
		for (n = 0; n < 3; n++)
		{
			this->mMiniBoardArray[i][n]->clearCell();
		}
	}
}