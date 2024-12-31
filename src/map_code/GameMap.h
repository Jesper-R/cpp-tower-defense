#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GridCell.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class GameMap {
	vector<vector<GridCell>> map;
	sf::Vector2i startGridLoc;
	sf::Vector2i endGridLoc;
	vector<sf::Vector2i> turnGridLocs;
	int width, height;
	int startingMoney, startingLives;
public:
	GameMap();
	int getGridWidth();
	int getGridHeight();
	void loadMapFromFile(std::string filename);
	void render(sf::RenderWindow &window);
	void getMapInfo();
	bool isBlocked(sf::Vector2i gridLoc);
	void update();
	int getStartingMoney();
	int getStartingLives();
	sf::Vector2i getStartGridLoc();
	sf::Vector2i getEndGridLoc();
	vector<sf::Vector2i> getTurnGridLocs();
	sf::Vector2i gridToPixel(sf::Vector2i gridLoc);
	sf::Vector2i pixelToGrid(sf::Vector2i pixelLoc);
	//GridCell* getGridCell(int x, int y);
	//std::vector<std::vector<GridCell>> const getMap();
};

#endif //GAMEMAP_H
