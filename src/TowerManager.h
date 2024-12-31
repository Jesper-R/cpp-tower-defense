//
// Created by Jesper Rudegran on 2024-12-31.
//

#ifndef TOWERMANAGER_H
#define TOWERMANAGER_H
#include <vector>

#include "SFML/System/Vector2.hpp"
#include "tower_code/Tower.h"

using namespace std;


class TowerManager {
    vector<Tower*> towers;
    vector<sf::Vector2i> occupiedGridLocs;
public:
    TowerManager();
    ~TowerManager();
    void placeTower(sf::Vector2i gridLoc, string towerType, GameMap* gameMap, Player* player);
    void update();
    void render(sf::RenderWindow& window);
};



#endif //TOWERMANAGER_H
