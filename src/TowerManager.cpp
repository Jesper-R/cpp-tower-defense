//
// Created by Jesper Rudegran on 2024-12-31.
//

#include "TowerManager.h"

#include <iostream>

#include "map_code/GameMap.h"
#include "tower_code/StoneThrower.h"
#include "tower_code/Wizard.h"



TowerManager::TowerManager(WaveManager *waveManager) {
    this->waveManager = waveManager;
}

TowerManager::~TowerManager() {
}

void TowerManager::placeTower(sf::Vector2i gridLoc, string towerType, GameMap* gameMap, Player* player) {
    Tower* tower = nullptr;
    if (gameMap->isBlocked(gridLoc)) {
        cout << "Position is blocked" << endl;
        return;
    }
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
        tower = new StoneThrower(100, 10, 1, 50, "../src/assets/towers/lvl1/stoneThrower.png", player, &projectileManager, waveManager);
    } else if (towerType == "wizard") {
        if (player->getMoney() < 100) {
            cout << "Not enough money" << endl;
            return;
        }
        tower = new Wizard(200, 20, 1, 100, "../src/assets/towers/lvl1/wizard.png", player);
    }

    tower->setTowerPos(pixelLoc);
    towers.push_back(tower);
}

void TowerManager::update() {
    float deltaTime = clock.restart().asSeconds();
    for (auto& tower : towers) {
        tower->update(deltaTime);
    }
    projectileManager.update();
}

void TowerManager::render(sf::RenderWindow& window) {
    for (auto& tower : towers) {
        tower->render(window);
    }
    projectileManager.render(window);
}
