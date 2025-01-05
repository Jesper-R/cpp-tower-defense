#ifndef GRIDCELL_H
#define GRIDCELL_H

#include <SFML/System/Vector2.hpp>
#include "CellBlock.h"
#include <string>
using namespace std;

class GridCell {
    bool containsTower;
    bool isBlocked;
    CellBlock* path = nullptr;
    sf::Vector2u gridPos;
public:
    GridCell();
    GridCell(sf::Vector2u gridPos, string pathType, string pathName, bool isBlocked);
    string getPathType() const;
    string getPathName() const;
    CellBlock* getPath() const;
    void setIsBlocked(bool isBlocked);
    bool getIsBlocked() const;
};

#endif //GRIDCELL_H
