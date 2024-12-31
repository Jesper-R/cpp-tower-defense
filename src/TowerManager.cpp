//
// Created by Jesper Rudegran on 2024-12-31.
//

#include "TowerManager.h"

#include <iostream>

#include "map_code/GameMap.h"
#include "tower_code/StoneThrower.h"

TowerManager::TowerManager() {
}

TowerManager::~TowerManager() {
}

void TowerManager::placeTower(sf::Vector2i gridLoc, string towerType, GameMap* gameMap, Player* player) {
    Tower* tower = nullptr;
    if (find(occupiedGridLocs.begin(), occupiedGridLocs.end(), gridLoc) != occupiedGridLocs.end()) {
        cout << "Tower already placed here" << endl;
        return;
    }
    occupiedGridLocs.push_back(gridLoc);
    sf::Vector2i pixelLoc = gameMap->gridToPixel(gridLoc);


    if (towerType == "basic") {
        if (player->getMoney() < 50) {
            cout << "Not enough money" << endl;
            return;
        }
        tower = new StoneThrower(100, 10, 1, 50, "../src/assets/towers/lvl1/stoneThrower.png", player);
    } else if (towerType == "big") {
        //tower = new Tower(200, 20, 1, "../src/assets/towers/BigTower.png");
    }

    tower->setTowerPos(pixelLoc);
    towers.push_back(tower);
}

void TowerManager::update() {
}

void TowerManager::render(sf::RenderWindow& window) {
    for (auto& tower : towers) {
        tower->render(window);
    }
}
