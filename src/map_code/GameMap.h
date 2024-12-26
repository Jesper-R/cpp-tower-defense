#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GridCell.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class GameMap {
	vector<vector<GridCell>> map;
	int width, height;
public:
	GameMap();
	int getWidth();
	int getHeight();
	void loadMapFromFile(std::string filename);
	void render(sf::RenderWindow &window);
	void getMapInfo();
	//GridCell* getGridCell(int x, int y);
	//std::vector<std::vector<GridCell>> const getMap();
};

#endif //GAMEMAP_H
