#include "Cell.h"

Cell::Cell(void) :sf::RectangleShape()
{
	this->setSize(sf::Vector2f(40,40));
	this->setFillColor(sf::Color::Green);
	this->setPosition(sf::Vector2f(10, 50));
	this->setOutlineThickness(-4);
}

Cell::~Cell(void)
{

}

Cell::Cell(sf::Vector2f &baseCoord) :sf::RectangleShape()
{
	this->setSize(sf::Vector2f(40, 40));
	this->setFillColor(sf::Color::Green);
	this->setPosition(baseCoord);
	this->setOutlineThickness(-4);
}

void Cell::draw(sf::RenderWindow &window)
{
	window.draw(*this);
	window.draw(this->getCellCharacter());
}

void Cell::draw(sf::RenderWindow &window, sf::Vector2i &mousePosition, int &p, int &q, MiniBoardPosition &miniPos)
{
	if ((p == miniPos.row) && (q == miniPos.column) && (mousePosition.x < (this->getPosition().x + this->getSize().x)) && (mousePosition.y < (this->getPosition().y + this->getSize().y)) &&
		(mousePosition.x > this->getPosition().x) && (mousePosition.y > this->getPosition().y))
	{
		this->setFillColor(sf::Color::Cyan);
	}
	else if ((p == miniPos.row) && (q == miniPos.column))
		this->setFillColor(sf::Color::Green);
	else
		this->setFillColor(sf::Color::White);
	window.draw(*this);
	window.draw(this->mCellCharacter);
}

sf::Text Cell::getCellCharacter(void)
{
	return this->mCellCharacter;
}

void Cell::setCellCharacter(int &i, int &n, sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font, int &playerNumber,int &p, int &q, MiniBoardPosition &miniPos)
{
	if ((this->getCellCharacter().getString().isEmpty())&&(p==miniPos.row)&&(q==miniPos.column)&&
		((mousePosition.x < (this->getPosition().x + this->getSize().x)) && 
		(mousePosition.y < (this->getPosition().y + this->getSize().y)) &&
		(mousePosition.x > this->getPosition().x) && (mousePosition.y > this->getPosition().y)))
	{
		if (playerNumber == 0)
			playerNumber = 1;
		else if (playerNumber == 1)
			playerNumber = 0;
		this->mCellCharacter.setString(newChar);
		this->mCellCharacter.setFillColor(sf::Color::Magenta);
		this->mCellCharacter.setFont(font);
		this->mCellCharacter.setCharacterSize(this->getSize().x);
		this->mCellCharacter.setPosition(sf::Vector2f(this->getPosition() + sf::Vector2f((this->getSize().x/5), -(this->getSize().y/7))));
		miniPos.row = i;
		miniPos.column = n;
	}
}

void Cell::setCellCharacter(const sf::String &newChar)
{
	this->mCellCharacter.setString(newChar);
}

void Cell::setCellCharacter(sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font)
{
	if ((this->getCellCharacter().getString().isEmpty()) && ((mousePosition.x < (this->getPosition().x + this->getSize().x)) &&
		(mousePosition.y < (this->getPosition().y + this->getSize().y)) &&
		(mousePosition.x > this->getPosition().x) && (mousePosition.y > this->getPosition().y)))
	{
		this->mCellCharacter.setString(newChar);
		this->mCellCharacter.setFillColor(sf::Color::Magenta);
		this->mCellCharacter.setFont(font);
		this->mCellCharacter.setCharacterSize(this->getSize().x/(newChar.toWideString().length()));
		this->mCellCharacter.setPosition(sf::Vector2f(this->getPosition() + sf::Vector2f((this->getSize().x / 5), -(this->getSize().y /(newChar.toWideString().length()* 7)))));
	}
}

bool Cell::isClaimed(void)
{
	if (this->mCellCharacter.getString().isEmpty())
		return false;
	else
		return true;
}