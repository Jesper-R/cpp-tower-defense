#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include <vector>
#include "WaveData.h"
#include "../map_code/GameMap.h"
#include "../enemy_code/Enemy.h"
#include <SFML/Graphics.hpp>

#include "../Player.h"
using namespace std;

class WaveManager {
    int currentWave = 1;
    vector<WaveData> waves;
    vector<shared_ptr<Enemy>> enemies;
    sf::Clock clock;
    void spawnWave(WaveData wave, GameMap& map);
public:
    ~WaveManager();
    WaveManager();
    void startWaveSpawning(GameMap& map);
    static bool isWaveDefeated(const WaveData& wave);
    void loadWaveData();
    vector<Enemy*> getEnemies();
    void removeEnemy(shared_ptr<Enemy> enemy);
    void update(Player& player, sf::RenderWindow& window, GameMap& map);
    void render(sf::RenderWindow& window);
};

#endif //WAVEMANAGER_H
