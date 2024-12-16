//
// Created by Jespe on 2024-12-15.
//

#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GridCell.h"
#include <string>
#include <vector>


class GameMap {
	std::vector<std::vector<GridCell>> map;
	int width, height;
	public:
	GameMap();
	GridCell* getGridCell(int x, int y);
public:
	void loadMapFromFile(std::string filename);
	void render();
	std::vector<std::vector<GridCell>> const getMap();
};




#endif //GAMEMAP_H
