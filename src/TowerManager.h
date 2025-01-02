//
// Created by Jesper Rudegran on 2024-12-31.
//

#ifndef TOWERMANAGER_H
#define TOWERMANAGER_H
#include <vector>

#include "projectile_code/ProjectileManager.h"
#include "SFML/System/Vector2.hpp"
#include "tower_code/Tower.h"

using namespace std;


class TowerManager {
    vector<Tower*> towers;
    ProjectileManager projectileManager;
    WaveManager* waveManager;
    vector<sf::Vector2i> occupiedGridLocs;
    sf::Clock clock;
public:
    TowerManager(WaveManager* waveManager);
    ~TowerManager();
    void placeTower(sf::Vector2i gridLoc, string towerType, GameMap* gameMap, Player* player);
    void update();
    void render(sf::RenderWindow& window);
};



#endif //TOWERMANAGER_H
