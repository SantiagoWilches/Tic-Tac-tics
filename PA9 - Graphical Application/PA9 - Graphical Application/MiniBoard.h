#include "Cell.h"
/*This class contains a 2d array of pointers to nine cells.
It inherits other attributes from the cell class*/
class MiniBoard :public Cell
{
public:
	MiniBoard(void);
	~MiniBoard(void);
	MiniBoard(sf::Vector2f &position);

	virtual void setCellCharacter(sf::Vector2i &mousePosition, sf::String &playerString, sf::Font &font, int &playerNumber, int &p, int &q, MiniBoardPosition &miniPos);
	void virtual draw(sf::RenderWindow &window, sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font, int &p, int &q, MiniBoardPosition &miniPos);
	virtual bool isWon(sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font);
private:
	Cell *mMiniBoardArray[3][3];
};