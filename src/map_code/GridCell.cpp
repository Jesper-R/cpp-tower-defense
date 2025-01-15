#include "GridCell.h"

#include <iostream>

#include "CellBlock.h"
#include <string>
using namespace std;

GridCell::~GridCell() {
	std::cout << "GridCell destructor" << std::endl;
}

GridCell::GridCell() {
	this->block = nullptr;
	this->gridPos = sf::Vector2i(0, 0);
	this->isBlocked = false;
	this->containsTower = false;
}

GridCell::GridCell(sf::Vector2i gridPos, string blockType, string blockName, bool isBlocked) {
	this->block = make_shared<CellBlock>(blockType, blockName);
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

string GridCell::getBlockType() const {
	return this->block->getBlockType();
}

string GridCell::getBlockName() const {
	return this->block->getBlockName();
}

CellBlock& GridCell::getBlock() {
	return *block;
}

