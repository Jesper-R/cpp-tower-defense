#include "CellBlock.h"
#include <random>
#include <vector>
#include <string>
using namespace std;

CellBlock::CellBlock() {
    this->blockType = "unknown";
    this->blockName = "unknown";
}

CellBlock::CellBlock(std::string blockType) {
    this->blockType = blockType;

    int totalOdds = 0;
    for (const auto& option : odds) {
        totalOdds += option.odds;
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    uniform_int_distribution<> dis(0, totalOdds - 1);
    int randomValue = dis(gen);

    int cumulativeOdds = 0;
    for (const auto& option : odds) {
        cumulativeOdds += option.odds;
        if (randomValue < cumulativeOdds) {
            this->blockName = option.blockName;
            break;
        }
    }
}

CellBlock::CellBlock(string blockType, string blockName) {
    this->blockType = blockType;
    this->blockName = blockName;
}

string CellBlock::getBlockName() const {
    return this->blockName;
}

string CellBlock::getBlockType() const {
    return this->blockType;
}