#ifndef TOWERMANAGER_H
#define TOWERMANAGER_H
#include <vector>

#include "projectile_code/ProjectileManager.h"
#include "SFML/System/Vector2.hpp"
#include "tower_code/Tower.h"
using namespace std;

class TowerManager : public Manager<Tower> {
    //vector<shared_ptr<Tower>> towers;
    vector<sf::Vector2i> occupiedGridLocs;
    sf::Clock clock;
public:
    TowerManager();
    ~TowerManager();
    void placeTower(sf::Vector2i gridLoc, string towerType, GameMap& gameMap, Player& player);
    void update(WaveManager& waveManager, ProjectileManager& projectileManager);
    void render(sf::RenderWindow& window);
};

#endif //TOWERMANAGER_H
