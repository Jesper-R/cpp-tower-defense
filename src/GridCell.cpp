//
// Created by Jespe on 2024-12-15.
//

#include "GridCell.h"
#include "path.h"
#include <string>

using namespace std;

GridCell::GridCell() {
}

GridCell::GridCell(sf::Vector2u gridPos, string pathType, string pathName) {
	this->path = new Path(pathType, pathName);
	this->gridPos = gridPos;
}

bool GridCell::canPlace() {
}

void GridCell::setOccupant() {
}

void GridCell::clearOccupant() {
}

string GridCell::getPathType() {
	return this->path->getPathType();
}

string GridCell::getPathName() {
	return this->path->getPathName();
}

Path * GridCell::getPath() {
	return this->path;
}
