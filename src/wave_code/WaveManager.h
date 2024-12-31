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
using namespace std;

class WaveManager {
    int currentWave = 1;
    vector<WaveData> waves;
    GameMap map;
    vector<Enemy*> enemies;
    sf::Clock clock;

    void spawnWave(WaveData wave);
public:
    WaveManager();
    WaveManager(GameMap map);

    void setGameMap(GameMap map);

    void startWaveSpawning();
    bool isWaveDefeated(WaveData wave);
    void loadWaveData();
    void update();
    void render(sf::RenderWindow& window);
};



#endif //WAVEMANAGER_H
