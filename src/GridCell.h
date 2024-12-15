//
// Created by Jespe on 2024-12-15.
//

#ifndef GRIDCELL_H
#define GRIDCELL_H

#include <SFML/System/Vector2.hpp>



class GridCell {
  bool containsTower;
  sf::Vector2u gridPos;
  //occupant
public:
  GridCell(sf::Vector2u gridPos);
  bool canPlace();
  void setOccupant();
  void clearOccupant();
};



#endif //GRIDCELL_H
