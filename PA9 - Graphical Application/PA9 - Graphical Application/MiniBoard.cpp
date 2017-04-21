#include "MiniBoard.h"

MiniBoard::MiniBoard(void)
{
	this->mMiniBoardArray[0][0] = nullptr;
	this->mMiniBoardArray[0][1] = nullptr;
	this->mMiniBoardArray[0][2] = nullptr;
	this->mMiniBoardArray[1][0] = nullptr;
	this->mMiniBoardArray[1][1] = nullptr;
	this->mMiniBoardArray[1][2] = nullptr;
	this->mMiniBoardArray[2][0] = nullptr;
	this->mMiniBoardArray[2][1] = nullptr;
	this->mMiniBoardArray[2][2] = nullptr;
	this->setSize(sf::Vector2f(140, 140));
	this->setFillColor(sf::Color::Green);
	this->setPosition(sf::Vector2f(10, 50));
	this->setOutlineThickness(-8);
}

MiniBoard::~MiniBoard(void)
{

}

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