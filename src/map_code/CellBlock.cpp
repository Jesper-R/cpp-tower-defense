#include "CellBlock.h"
#include <random>
#include <vector>
#include <string>
using namespace std;

struct PathOption {
    int odds;
    string pathName;
};

vector<PathOption> options = {
    {80, "flowers_1"},
    {80, "flowers_2"},
    {5, "pond"},
    {5, "stone"},
    {700, "grass"}
};

CellBlock::CellBlock(std::string pathType) {
    this->pathType = pathType;

    int totalOdds = 0;
    for (const auto& option : options) {
        totalOdds += option.odds;
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    uniform_int_distribution<> dis(0, totalOdds - 1);
    int randomValue = dis(gen);

    int cumulativeOdds = 0;
    for (const auto& option : options) {
        cumulativeOdds += option.odds;
        if (randomValue < cumulativeOdds) {
            this->pathName = option.pathName;
            break;
        }
    }
}

CellBlock::CellBlock(string pathType, string pathName) {
    this->pathType = pathType;
    this->pathName = pathName;
}

string CellBlock::getPathName() const {
    return this->pathName;
}

string CellBlock::getPathType() const {
    return this->pathType;
}