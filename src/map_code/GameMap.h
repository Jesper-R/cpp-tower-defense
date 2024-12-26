//
// Created by Jespe on 2024-12-15.
//

#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GridCell.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>


class GameMap {
	std::vector<std::vector<GridCell>> map;
	int width, height;
	public:
	GameMap();
	GridCell* getGridCell(int x, int y);
	int getWidth();
	int getHeight();
public:
	void loadMapFromFile(std::string filename);
	void render(sf::RenderWindow &window);
	std::vector<std::vector<GridCell>> const getMap();
	void getMapInfo();
};




#endif //GAMEMAP_H
