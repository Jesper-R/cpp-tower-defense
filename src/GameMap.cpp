//
// Created by Jespe on 2024-12-15.
//

#include "GameMap.h"
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using namespace std;
using json = nlohmann::json;

GameMap::GameMap() {

}

GridCell * GameMap::getGridCell(int x, int y) {
}

void GameMap::loadMapFromFile(std::string filename) {
    cout << "starting to load from file" << endl;
    ifstream file("../src/" + filename);

    if (!file.is_open())
        throw runtime_error("Could not open file " + filename);

    json mapData;
    file >> mapData;

    this->width = mapData["width"];
    this->height = mapData["height"];
    vector<vector<GridCell>> map(width, vector<GridCell>(height, GridCell()));

    for (auto path: mapData["paths"]) {
        int x = path["x"];
        int y = path["y"];
        string pathType = path["path_type"];

        map[x][y] = GridCell(sf::Vector2u(x, y));
    }

    this->map = map;
    cout << "finished loading from file" << endl;
}

void GameMap::render() {
}

std::vector<std::vector<GridCell>> const GameMap::getMap() {
    return this->map;
}
