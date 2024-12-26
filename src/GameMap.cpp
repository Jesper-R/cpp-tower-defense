#include "GameMap.h"
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

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
    vector map(width, vector<GridCell>(height));

    auto initializeGridCell = [&](const json& path, const string& pathType, bool blocksPlacement = true) {
        int x = path["x"];
        int y = path["y"];
        string pathName = path["path_name"];
        map[x][y] = GridCell(sf::Vector2u(x, y), pathType, pathName, blocksPlacement);
    };

    for (const auto& path : mapData["paths"]) {
        initializeGridCell(path, "paths");
    }

    for (const auto& path : mapData["grid_blocks"]) {
        bool blocksPlacement = (path["path_name"] == "pond" || path["path_name"] == "stone");
        initializeGridCell(path, "grid_blocks", blocksPlacement);
    }

    for (const auto& path : mapData["turn_paths"]) {
        initializeGridCell(path, "paths");
    }

    // Fills in the rest of the map with randomzied blocks
    for (int i = 0; i < width; ++i) {
       for (int j = 0; j < height; ++j) {
           Path* path = map[i][j].getPath();
           if (!path) {
               map[i][j] = GridCell(sf::Vector2u(i, j), "grid_blocks", Path("grid_blocks").getPathName());
           }
       }
    }


    this->map = map;
    cout << "finished loading from file" << endl;
}

void GameMap::render(sf::RenderWindow &window) {
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            sf::Texture texture;
            Path* path = map[i][j].getPath();
            string documentPath = "0";
            if(path) {
                documentPath = "../src/assets/" + path->getPathType() + "/" + path->getPathName() + ".png";
            }
            if (path && !texture.loadFromFile("../src/assets/" + path->getPathType() + "/" + path->getPathName() + ".png")) {
                std::cout << "Failed to load texture" << std::endl;
            }
            sf::Sprite sprite;
            sprite.setPosition(i * 64, (height - j - 1) * 64);
            sprite.setTexture(texture);
            window.draw(sprite);
        }
    }
}



std::vector<std::vector<GridCell>> const GameMap::getMap() {
    return this->map;
}

void GameMap::getMapInfo() {
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            GridCell* cell = &map[i][j];
            cout << "GridCell at (" << i << ", " << j << ") with pathType: " << map[i][j].getPathType() << " and pathName: " << map[i][j].getPathName() << " isBlocked: " << cell->getIsBlocked() << endl;
        }
    }
}

int GameMap::getWidth() {
    return width;
}

int GameMap::getHeight() {
    return height;
}
