#ifndef GRIDCELL_H
#define GRIDCELL_H

#include <SFML/System/Vector2.hpp>
#include "CellBlock.h"
#include <string>
using namespace std;

class GridCell {
    bool containsTower;
    bool isBlocked;
    bool isPath;
    bool isTurn;

    CellBlock* path = nullptr;
    sf::Vector2u gridPos;
public:
    string getPathType();
    string getPathName();
    CellBlock * getPath();
    GridCell();
    GridCell(sf::Vector2u gridPos, string pathType, string pathName);
    GridCell(sf::Vector2u gridPos, string pathType, string pathName, bool isBlocked);
    bool canPlace();
    void setIsBlocked(bool isBlocked);
    void setOccupant();
    void clearOccupant();
    bool getIsBlocked();
};

#endif //GRIDCELL_H
