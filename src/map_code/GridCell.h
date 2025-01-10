#ifndef GRIDCELL_H
#define GRIDCELL_H

#include <SFML/System/Vector2.hpp>
#include "CellBlock.h"
#include <string>
using namespace std;

class GridCell {
    bool containsTower;
    bool isBlocked;
    CellBlock* block;
    sf::Vector2i gridPos;
public:
    GridCell();
    GridCell(sf::Vector2i gridPos, string blockType, string blockName, bool isBlocked);
    string getBlockType() const;
    string getBlockName() const;
    CellBlock* getBlock() const;
    void setIsBlocked(bool isBlocked);
    bool getIsBlocked() const;
};

#endif //GRIDCELL_H
