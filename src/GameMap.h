//
// Created by Jespe on 2024-12-15.
//

#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GridCell.h"



class GameMap {
	GridCell gridCells[20][11];
	public:
	GameMap();
	GridCell* getGridCell(int x, int y);


};



#endif //GAMEMAP_H
