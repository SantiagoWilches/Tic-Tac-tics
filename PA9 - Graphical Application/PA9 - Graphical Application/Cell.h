#include <iostream>
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct player
{
	sf::String playerOne;
	sf::String playerTwo;
}Player;

typedef struct miniBoardPosition
{
	int row = 1;
	int column = 1;
}MiniBoardPosition;

class Cell :public sf::RectangleShape
{
public:
	Cell(void);
	~Cell(void);
	Cell(sf::Vector2f &baseCoord);

	virtual void draw(sf::RenderWindow &window, sf::Vector2i &mousePosition, int &p, int &q, MiniBoardPosition &miniPos);
	virtual void draw(sf::RenderWindow &window);
	sf::Text getCellCharacter(void);
	virtual void setCellCharacter(int &i, int &n, sf::Vector2i &mousePosition, sf::String &PlayerString, sf::Font &font, int &playerNumber, int &p, int &q, MiniBoardPosition &miniPos);
	virtual void setCellCharacter(sf::Vector2i &mousePosition, sf::String &newChar, sf::Font &font);
	virtual void setCellCharacter(const sf::String &newChar);
	bool isClaimed(void);

private:
	sf::Text mCellCharacter;
};
