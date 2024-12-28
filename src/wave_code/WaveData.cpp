#include "WaveData.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

WaveData::WaveData() {
    loadWaveData();
}

void WaveData::loadWaveData() {
    ifstream file("../src/map.json");

    if (!file.is_open())
        throw runtime_error("Could not open file map.json");

    json mapData;
    file >> mapData;

    auto wave = mapData["waves"][waveNumber];
    nextWaveDelay = wave["next_wave_delay_ms"];

    EnemyGroup group;
    group.nextGroupDelay = wave["next_wave_delay_ms"];
    group.spawnDelay = wave["spawn_delay_ms"];

    for (const auto& enemies : wave["enemies"]) {
        group.enemyType = enemies["enemy_type"];
        group.count = enemies["count"];
        waveComposition.push_back(group);
    }
}
