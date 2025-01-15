#include "GameMap.h"
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using json = nlohmann::json;

GameMap::~GameMap() {
    std::cout << "GameMap destructor" << std::endl;
}

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

    this->map.resize(width);
    for (int i = 0; i < width; ++i) {
        this->map[i].resize(height);
    }

    auto initializeGridCell = [&](const json& path, const string& pathType, bool blocksPlacement = false)
    {
        int x = path["x"];
        int y = path["y"];
        string pathName = path["path_name"];
        if (pathName == "pond" || pathName == "stone") {
            blocksPlacement = true;
        }
        this->map[x][y] = GridCell(sf::Vector2i(x, y), pathType, pathName, blocksPlacement);
    };

    for (const auto& path : mapData["paths"]) {
        initializeGridCell(path, "paths");
    }

    for (const auto& path : mapData["grid_blocks"]) {
        initializeGridCell(path, "grid_blocks");
    }

    for (const auto& path : mapData["turn_paths"]) {
        initializeGridCell(path, "paths");
        sf::Vector2i position(path["x"], path["y"]);
        turnGridLocs.push_back(position);
    }

    for (int i = 0; i < width; ++i) {
       for (int j = 0; j < height; ++j) {
           CellBlock* path = &this->map[i][j].getBlock();
           if (!path) {
               bool blocksPlacement = false;
               this->map[i][j] = GridCell(sf::Vector2i(i, j), "grid_blocks", CellBlock("grid_blocks").getBlockName(), blocksPlacement);
           }
       }
    }
}

void GameMap::render(sf::RenderWindow &window) {
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            sf::Texture texture;
            CellBlock* path = &map[i][j].getBlock();
            if (path && !texture.loadFromFile("../src/assets/" + path->getBlockType() + "/" + path->getBlockName() + ".png")) {
                throw runtime_error("Failed to load texture: " + path->getBlockName());
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
            string pathName = map[i][j].getBlockName();
            string pathType = map[i][j].getBlockType();
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

sf::Vector2i GameMap::getStartGridLoc() const {
    return this->startGridLoc;
}

sf::Vector2i GameMap::getEndGridLoc() const {
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
