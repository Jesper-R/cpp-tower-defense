#include "GridCell.h"
#include "CellBlock.h"
#include <string>
using namespace std;

GridCell::GridCell() {
	this->path = nullptr;
	this->gridPos = sf::Vector2u(0, 0);
	this->isBlocked = false;
	this->containsTower = false;
}

GridCell::GridCell(sf::Vector2u gridPos, string pathType, string pathName, bool isBlocked) {
	this->path = new CellBlock(pathType, pathName);
	this->gridPos = gridPos;
	this->isBlocked = isBlocked;
	this->containsTower = false;
}

void GridCell::setIsBlocked(bool isBlocked) {
	this->isBlocked = isBlocked;
}

bool GridCell::getIsBlocked() const {
	return this->isBlocked;
}

string GridCell::getPathType() const {
	return this->path->getPathType();
}

string GridCell::getPathName() const {
	return this->path->getPathName();
}

CellBlock * GridCell::getPath() const {
	return this->path;
}
