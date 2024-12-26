//
// Created by Jespe on 2024-12-15.
//

#ifndef GRIDCELL_H
#define GRIDCELL_H

#include <SFML/System/Vector2.hpp>
#include "path.h"
#include <string>
using namespace std;

class GridCell {
    bool containsTower;
    Path* path = nullptr;

    sf::Vector2u gridPos;
    //occupant

public:
    string getPathType();
    string getPathName();

    Path * getPath();

    GridCell();
    GridCell(sf::Vector2u gridPos, string pathType, string pathName);
    bool canPlace();
    void setOccupant();
    void clearOccupant();
};



#endif //GRIDCELL_H
