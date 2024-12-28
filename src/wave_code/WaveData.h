//
// Created by Jesper Rudegran on 2024-12-28.
//

#ifndef WAVEDATA_H
#define WAVEDATA_H

#include <vector>
#include <string>
using namespace std;

struct EnemyGroup {
    string enemyType;
    int count;
    int spawnDelay;
    int nextGroupDelay;
};

class WaveData {
    int nextWaveDelay;
    int waveNumber;
    int enemyCount;
    vector<EnemyGroup> waveComposition;
public:
    WaveData();
    void loadWaveData();
};



#endif //WAVEDATA_H
