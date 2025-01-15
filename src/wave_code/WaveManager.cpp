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

void WaveManager::spawnWave(WaveData wave, GameMap& map) {
    thread([this, wave, &map]() {
        int currentGroup = 1;
        for (const auto& group : wave.getWaveComposition()) {
            for (int i = 0; i < group.count; ++i) {
                if (i != 0) {
                    this_thread::sleep_for(chrono::milliseconds(group.spawnDelay));
                }

                shared_ptr<Enemy> enemy = nullptr;
                if (group.enemyType == "basic") {
                    enemy = make_shared<BasicEnemy>();
                } else if (group.enemyType == "big") {
                    enemy = make_shared<BigEnemy>();
                }
                if (enemy) {
                    addObject(enemy);
                    enemy->setPath(map);
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

WaveManager::~WaveManager() {
    cout << "WaveManager destructor" << endl;
}

WaveManager::WaveManager() {}

void WaveManager::startWaveSpawning(GameMap& map) {
    cout << "Starting wave spawning" << endl;
    spawnWave(waves[currentWave-1], map);
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
    vector<Enemy*> enemyPtrs;
    for (auto& enemy : getObjects()) {
        enemyPtrs.push_back(enemy.get());
    }
    return enemyPtrs;
}

void WaveManager::removeEnemy(shared_ptr<Enemy> enemy) {
    removeObject(enemy);
    waves[currentWave - 1].decrementEnemiesLeft();
}

void WaveManager::update(Player& player, sf::RenderWindow& window, GameMap& map) {
    vector<shared_ptr<Enemy>> toRemove;
    float deltaTime = clock.restart().asSeconds();
    for (auto& enemy : getObjects()) {
        enemy->update(deltaTime);
        if (enemy->isDead()) {
            player.addMoney(enemy->getValue());
            toRemove.push_back(enemy);
        }
        if (enemy->hasReachedEnd()) {
            player.removeLife(enemy->getDamage());
            player.update(window);
            toRemove.push_back(enemy);
        }
    }
    for (auto& enemy : toRemove) {
        removeEnemy(enemy);
    }

    if (isWaveDefeated(waves[currentWave-1])) {
        currentWave++;
        if (currentWave <= waves.size()) {
            spawnWave(waves[currentWave-1], map);
        } else {
            cout << "All waves defeated" << endl;
            window.close();
        }
    }
}

void WaveManager::render(sf::RenderWindow &window) {
    for (auto enemy : getObjects()) {
        enemy->render(window);
    }
}

