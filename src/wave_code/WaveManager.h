//
// Created by Jesper Rudegran on 2024-12-27.
//

#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include <vector>
#include "WaveData.h"
#include "../enemy_code/Enemy.h"
using namespace std;

class WaveManager {
    int currentWave;
    vector<WaveData> waves;
    vector<Enemy*> enemies;
public:
    WaveManager();

    void startWaveSpawning();
    bool isWaveDefeated();
    void loadWaveData();
};



#endif //WAVEMANAGER_H
