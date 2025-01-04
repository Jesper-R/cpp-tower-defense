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
        int currentGroup = 1;
        for (const auto& group : wave.getWaveComposition()) {
            for (int i = 0; i < group.count; ++i) {
                //this_thread::sleep_for(chrono::milliseconds(group.spawnDelay));
                if (i == 0) {} else {
                    cout << "ENEMY SLEEP" << endl;
                    this_thread::sleep_for(chrono::milliseconds(group.spawnDelay));
                }

                Enemy* enemy = nullptr;
                if (group.enemyType == "basic") {
                    enemy = new BasicEnemy();
                } else if (group.enemyType == "big") {
                    enemy = new BigEnemy();
                }
                if (enemy) {
                    enemies.push_back(enemy);
                    enemy->setPath(&map);
                    enemy->setCurrentPos(map.gridToPixel(map.getStartGridLoc()));
                }
            }
            if (currentGroup < wave.getWaveComposition().size()) {
                this_thread::sleep_for(chrono::milliseconds(group.nextGroupDelay));
            }

            cout << "Group done" << endl;
            currentGroup++;
            this_thread::sleep_for(chrono::milliseconds(group.spawnDelay));
        }
    }).detach();
}

WaveManager::WaveManager(Player* player, sf::RenderWindow* window) {
    this->player = player;
    this->window = window;
}

void WaveManager::setGameMap(GameMap map) {
    this->map = map;
}

void WaveManager::startWaveSpawning() {
    cout << "Starting wave spawning" << endl;
    spawnWave(waves[currentWave-1]);
}

bool WaveManager::isWaveDefeated(const WaveData& wave) {
    if (wave.getEnemiesLeft() == 0) {
        return true;
    }
    return false;
}

void WaveManager::loadWaveData() {
    ifstream file("../src/map.json");

    if (!file.is_open())
        throw runtime_error("Could not open or locate file map.json");

    json mapData;
    file >> mapData;

    for (auto wave : mapData["waves"]) {
        WaveData waveData;
        try {
            waveData = WaveData(wave["wave_nr"], wave["next_wave_delay_ms"]);
        } catch (const exception& e) {
            throw runtime_error("Error parsing wave data: " + string(e.what())); // throws it further to be catched in Game.cpp but sends with origin so we know where exactly it came from
        }
        waves.push_back(waveData);
    }
    cout << "Loaded wave data" << endl;
}

vector<Enemy*> WaveManager::getEnemies() {
    return enemies;
}

void WaveManager::removeEnemy(Enemy *enemy) {
    delete enemy;
    enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
    waves[currentWave-1].decrementEnemiesLeft();
}

void WaveManager::update() {
    vector<Enemy*> toRemove;
    //cout << "WaveManager update" << endl;
    float deltaTime = clock.restart().asSeconds();
    for (auto& enemy : enemies) {
        enemy->update(deltaTime);
        if (enemy->isDead()) {
            player->addMoney(enemy->getValue());
            toRemove.push_back(enemy);
        }
        if (enemy->hasReachedEnd()) {
            player->removeLife(enemy->getDamage());
            player->update(this->window);
            toRemove.push_back(enemy);
        }
    }
    for (auto& enemy : toRemove) {
        removeEnemy(enemy);
    }

    if (isWaveDefeated(waves[currentWave-1])) {
        currentWave++;
        if (currentWave <= waves.size()) {
            spawnWave(waves[currentWave-1]);
        } else {
            cout << "All waves defeated" << endl;
            window->close();
        }
    }
}

void WaveManager::render(sf::RenderWindow &window) {
    for (auto enemy : enemies) {
        enemy->render(window);
    }
}

