#include "GameMap.h"
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;
using json = nlohmann::json;

GameMap::GameMap() {
    this->width = 0;
    this->height = 0;
    this->startingMoney = 0;
    this->startingLives = 0;
}

void GameMap::loadMapFromFile(std::string filename) {
    ifstream file("../src/" + filename);

    if (!file.is_open())
        throw runtime_error("Could not open file " + filename);

    json mapData;
    file >> mapData;
    try {
        this->width = mapData["width"];
        this->height = mapData["height"];
        this->startGridLoc = sf::Vector2i(mapData["start"]["x"], mapData["start"]["y"]);
        this->endGridLoc = sf::Vector2i(mapData["end"]["x"], mapData["end"]["y"]);
        this->startingMoney = mapData["starting_money"];
        this->startingLives = mapData["starting_lives"];
    } catch (const std::exception& e) {
        throw runtime_error("Error parsing map data: " + string(e.what()));
    }

    vector map(width, vector<GridCell>(height));

    auto initializeGridCell = [&](const json& path, const string& pathType, bool blocksPlacement = false)
    {
        int x = path["x"];
        int y = path["y"];
        string pathName = path["path_name"];
        if (pathName == "pond" || pathName == "stone") {
            blocksPlacement = true;
        }
        map[x][y] = GridCell(sf::Vector2u(x, y), pathType, pathName, blocksPlacement);
    };

    for (const auto& path : mapData["paths"]) {
        initializeGridCell(path, "paths");
    }

    for (const auto& path : mapData["grid_blocks"]) {
        initializeGridCell(path, "grid_blocks");
    }

    for (const auto& path : mapData["turn_paths"]) {
        initializeGridCell(path, "paths");
        //int index = path["index"];

        sf::Vector2i position(path["x"], path["y"]);
        turnGridLocs.push_back(position);
        //turnGridLocs.push_back({index, position});
    }

    /*std::sort(turnGridLocs.begin(), turnGridLocs.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });*/

    for (int i = 0; i < width; ++i) {
       for (int j = 0; j < height; ++j) {
           CellBlock* path = map[i][j].getPath();
           if (!path) {
               bool blocksPlacement = false;

               map[i][j] = GridCell(sf::Vector2u(i, j), "grid_blocks", CellBlock("grid_blocks").getPathName(), blocksPlacement);
           }
       }
    }

    this->map = map;
}

void GameMap::render(sf::RenderWindow &window) {
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            sf::Texture texture;
            CellBlock* path = map[i][j].getPath();
            if (path && !texture.loadFromFile("../src/assets/" + path->getPathType() + "/" + path->getPathName() + ".png")) {
                throw runtime_error("Failed to load texture: " + path->getPathName());
            }
            sf::Sprite sprite;
            sprite.setPosition(i * 64, (height - j - 1) * 64);
            sprite.setTexture(texture);
            window.draw(sprite);
        }
    }
}

bool GameMap::isBlocked(sf::Vector2i gridLoc) {
    return map[gridLoc.x][gridLoc.y].getIsBlocked();
}

void GameMap::update() {
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            string pathName = map[i][j].getPathName();
            string pathType = map[i][j].getPathType();
            if (pathName == "pond" || pathName == "stone" || pathType == "paths" || pathType == "turn_paths") {
                map[i][j].setIsBlocked(true);
            }
        }
    }
}

int GameMap::getStartingMoney() const {
    return startingMoney;
}

int GameMap::getStartingLives() const {
    return startingLives;
}

sf::Vector2i GameMap::getStartGridLoc() {
    return this->startGridLoc;
}

sf::Vector2i GameMap::getEndGridLoc() {
    return this->endGridLoc;
}

sf::Vector2i GameMap::gridToPixel(sf::Vector2i gridLoc) {
    return sf::Vector2i(gridLoc.x * 64, 704 - 64 - (64 * gridLoc.y));
}

sf::Vector2i GameMap::pixelToGrid(sf::Vector2i pixelLoc) {
    return sf::Vector2i(pixelLoc.x / 64, (704 - pixelLoc.y) / 64);
}

vector<sf::Vector2i> GameMap::getTurnGridLocs() {
    return this->turnGridLocs;
}

int GameMap::getGridWidth() const {
    return width;
}

int GameMap::getGridHeight() const {
    return height;
}
