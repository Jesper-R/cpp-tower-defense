//
// Created by Jespe on 2024-12-15.
//

#include "GridCell.h"
#include <string>

using namespace std;

GridCell::GridCell() {
}

GridCell::GridCell(sf::Vector2u gridPos) {
	this->gridPos = gridPos;

}

bool GridCell::canPlace() {
}

void GridCell::setOccupant() {
}

void GridCell::clearOccupant() {
}
