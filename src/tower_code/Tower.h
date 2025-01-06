#ifndef TOWER_H
#define TOWER_H

#include "../GameObject.h"
#include "../Player.h"
#include "../projectile_code/ProjectileManager.h"
#include "../wave_code/WaveManager.h"

class Tower : public GameObject {
    int range;
    float damage;
    float attackSpeed;
    float attackTimer = 0.0f;
    int cost;
    ProjectileManager* projectileManager = nullptr;
    WaveManager* waveManager = nullptr;
    sf::Vector2i towerPos;
    sf::Vector2i getTargetPos(WaveManager* waveManager);
public:
    Tower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player* player, WaveManager* waveManager);
    void update(float deltaTime);
    void setTowerPos(sf::Vector2i pos);
    void setProjectileManager(ProjectileManager* projectileManager);
    int getRange() const;
    ProjectileManager* getProjectileManager() const;
    WaveManager* getWaveManager() { return waveManager; }
    virtual void attack(WaveManager* waveManager);
    virtual void render(sf::RenderWindow& window);
};

#endif //TOWER_H
