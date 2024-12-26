//
// Created by Jespe on 2024-12-15.
//

#include "Path.h"
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>

struct PathOption {
    int odds;
    std::string pathName;
};

std::vector<PathOption> options = {
    {80, "flowers_1"},
    {80, "flowers_2"},
    {5, "pond"},
    {5, "stone"},
    {700, "grass"}
};

Path::Path(std::string pathType) {
    std::cout << "Path constructor" << std::endl;
    this->pathType = pathType;

    int totalOdds = 0;
    for (const auto& option : options) {
        totalOdds += option.odds;
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, totalOdds - 1);
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

Path::Path(std::string pathType, std::string pathName) {
    this->pathType = pathType;
    this->pathName = pathName;
}

std::string Path::getPathName() {
    return this->pathName;
}

std::string Path::getPathType() {
    return this->pathType;
}