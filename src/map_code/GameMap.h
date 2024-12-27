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
	vector<pair<int, sf::Vector2i>> turnGridLocs;
	int width, height;
	int startingMoney, startingLives;
public:
	GameMap();
	int getGridWidth();
	int getGridHeight();
	void loadMapFromFile(std::string filename);
	void render(sf::RenderWindow &window);
	void getMapInfo();

	int getStartingMoney();
	int getStartingLives();
	//GridCell* getGridCell(int x, int y);
	//std::vector<std::vector<GridCell>> const getMap();
};

#endif //GAMEMAP_H
