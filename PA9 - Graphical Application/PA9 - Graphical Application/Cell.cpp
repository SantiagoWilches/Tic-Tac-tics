#include "Cell.h"
/*This default constructor is not defined but must be declared.*/
Cell::Cell(void) :sf::RectangleShape()
{
	
}
/*destructor for cell empty. no memory dynamically allocated*/
Cell::~Cell(void)
{

}
/*this constructor accepts coordinates passed in by the miniboard constructor.
These coordinates set the cell's position within the miniboard and the mainboard.
Also sets cell color, size, and border*/
Cell::Cell(sf::Vector2f &baseCoord) :sf::RectangleShape()
{
	this->setSize(sf::Vector2f(40, 40));
	this->setFillColor(sf::Color::Green);
	this->setPosition(baseCoord);
	this->setOutlineThickness(-4);
}
/*draws the cell as a rectangleshape and then draws the character associated
with the cell. If no character is associated with the cell, the cell hasn't
been selected by a player and isn't drawn. used in welcome window.*/
void Cell::draw(sf::RenderWindow &window)
{
	window.draw(*this);
	window.draw(this->getCellCharacter());
}
/*Draws cell in the RenderWindow. if the mousePosition is within the bounds
of the cell, it is drawn as cyan, if the miniboard the cell is in is active,
the cell is green, if the miniboard is inactive, the cell is white.*/
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
/*getter for the cellcharacter*/
sf::Text Cell::getCellCharacter(void)
{
	return this->mCellCharacter;
}
/*sets cell character based on the position of the mouse and which
player's turn it is. Character is not updated if the miniboard is not
active. also sets font and position for the character*/
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
/*this setter is used when a cell, miniboard, or mainboard is won.
player is not changed after this update. mainboard, or miniboard must
explicitly call this function or be cast to a cell*/
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
/*This check to see of there is a character associated with the cell yet*/
bool Cell::isClaimed(void)
{
	if (this->mCellCharacter.getString().isEmpty())
		return false;
	else
		return true;
}
/*Clears cells*/
void Cell::clearCell(void)
{
	this->mCellCharacter.setString("");
}