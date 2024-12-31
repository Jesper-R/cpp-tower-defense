#include "WaveData.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

WaveData::WaveData() {
    //loadGroupData();
}

WaveData::WaveData(int waveNumber, int nexWaveDelay) {
    this->waveNumber = waveNumber;
    this->nextWaveDelay = nexWaveDelay;
    loadGroupData(waveNumber);
}


void WaveData::loadGroupData(int waveNumber) {
    ifstream file("../src/map.json");

    if (!file.is_open())
        throw runtime_error("Could not open file map.json");

    json mapData;
    file >> mapData;

    auto wave = mapData["waves"][waveNumber-1];
    nextWaveDelay = wave["next_wave_delay_ms"];

    EnemyGroup group;
    group.nextGroupDelay = wave["next_group_delay_ms"];
    group.spawnDelay = wave["spawn_delay_ms"];

    for (const auto& enemies : wave["enemies"]) {

        group.enemyType = enemies["type"];
        group.count = enemies["count"];
        enemiesLeft += group.count;
        waveComposition.push_back(group);
    }
}
