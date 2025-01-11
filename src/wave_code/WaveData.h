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
    int enemiesLeft = 0;
    vector<EnemyGroup> waveComposition;
public:
    WaveData();
    WaveData(int waveNumber, int nexWaveDelay);
    void loadGroupData(int waveNumber);
    int getEnemiesLeft() const { return enemiesLeft; }
    void decrementEnemiesLeft() { enemiesLeft--; }
    vector<EnemyGroup> getWaveComposition() const { return waveComposition; }
};



#endif //WAVEDATA_H
