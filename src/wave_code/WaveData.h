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
    WaveData(int waveNumber, int nexWaveDelay);
    void loadGroupData(int waveNumber);
};



#endif //WAVEDATA_H
