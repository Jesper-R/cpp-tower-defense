//
// Created by Jesper Rudegran on 2024-12-27.
//

#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include <vector>
#include "WaveData.h"
#include "../map_code/GameMap.h"
#include "../enemy_code/Enemy.h"
#include <SFML/Graphics.hpp>

#include "../Player.h"
using namespace std;

class WaveManager {
    int currentWave = 1;
    vector<WaveData> waves;
    GameMap map;
    Player* player;
    sf::RenderWindow* window;
    vector<Enemy*> enemies;
    sf::Clock clock;

    void spawnWave(WaveData wave);
public:
    WaveManager(Player* player, sf::RenderWindow* window);

    void setGameMap(GameMap map);

    void startWaveSpawning();
    bool isWaveDefeated(WaveData wave);
    void loadWaveData();
    vector<Enemy*> getEnemies();
    void removeEnemy(Enemy* enemy);
    void update();
    void render(sf::RenderWindow& window);
};



#endif //WAVEMANAGER_H
