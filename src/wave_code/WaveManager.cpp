#include "WaveManager.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "../enemy_code/BasicEnemy.h"
#include "../enemy_code/BigEnemy.h"

using json = nlohmann::json;
using namespace std;

void WaveManager::spawnWave(WaveData wave) {
    thread([this, wave]() {
        for (const auto& group : wave.getWaveComposition()) {
            this_thread::sleep_for(chrono::milliseconds(group.nextGroupDelay));
            for (int i = 0; i < group.count; ++i) {
                Enemy* enemy = nullptr;
                if (group.enemyType == "basic") {
                    enemy = new BasicEnemy();
                } else if (group.enemyType == "big") {
                    enemy = new BigEnemy();
                }
                if (enemy) {
                    enemies.push_back(enemy);
                    //enemy->setPath(map.getStartGridLoc(), map.getEndGridLoc()); // add turn locs here later for pathfinding
                    enemy->setPath(&map);
                    enemy->setCurrentPos(map.gridToPixel(map.getStartGridLoc()));
                    //cout << "Spawned enemy" << endl;
                }
                this_thread::sleep_for(chrono::milliseconds(group.spawnDelay));
            }
        }
    }).detach();
}

WaveManager::WaveManager() {
    loadWaveData();
}

void WaveManager::setGameMap(GameMap map) {
    this->map = map;
}

void WaveManager::startWaveSpawning() {
    cout << "Starting wave spawning" << endl;
    spawnWave(waves[currentWave-1]);
}

bool WaveManager::isWaveDefeated(WaveData wave) {
    if (wave.getEnemiesLeft() == 0) {
        return true;
    }
    return false;
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
    cout << "Loaded wave data" << endl;
}

vector<Enemy*> WaveManager::getEnemies() {
    return enemies;
}

void WaveManager::update() {
    //cout << "WaveManager update" << endl;
    float deltaTime = clock.restart().asSeconds();
    for (auto enemy : enemies) {
        enemy->update(deltaTime);
    }
}

void WaveManager::render(sf::RenderWindow &window) {
    //cout << "WaveManager render" << endl;

    for (auto enemy : enemies) {
        //if (enemy != nullptr) {
            enemy->render(window);
        //}
        //enemy->render(window);
    }
}

