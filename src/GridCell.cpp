//
// Created by Jespe on 2024-12-15.
//

#include "GridCell.h"
#include "CellBlock.h"
#include <string>

using namespace std;

GridCell::GridCell() {
}

GridCell::GridCell(sf::Vector2u gridPos, string pathType, string pathName) {
	this->path = new CellBlock(pathType, pathName);
	this->gridPos = gridPos;
}

GridCell::GridCell(sf::Vector2u gridPos, string pathType, string pathName, bool isBlocked) {
	this->path = new CellBlock(pathType, pathName);
	this->gridPos = gridPos;
	this->isBlocked = isBlocked;
}

bool GridCell::canPlace() {
}

void GridCell::setOccupant() {
}

void GridCell::clearOccupant() {
}

bool GridCell::getIsBlocked() {
	return this->isBlocked;
}

string GridCell::getPathType() {
	return this->path->getPathType();
}

string GridCell::getPathName() {
	return this->path->getPathName();
}

CellBlock * GridCell::getPath() {
	return this->path;
}
