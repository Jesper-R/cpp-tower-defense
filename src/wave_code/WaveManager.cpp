//
// Created by Jesper Rudegran on 2024-12-27.
//

#include "WaveManager.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

WaveManager::WaveManager() {
    loadWaveData();
}

void WaveManager::startWaveSpawning() {
}

bool WaveManager::isWaveDefeated() {
}

void WaveManager::loadWaveData() {
    ifstream file("../src/map.json");

    if (!file.is_open())
        throw runtime_error("Could not open file map.json");

    json mapData;
    file >> mapData;

    for (auto wave : mapData["waves"]) {
        WaveData waveData = WaveData(wave["wave_nr"], wave["next_wave_delay_ms"]);
        waves.push_back(waveData);
    }
}
