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
    sf::Vector2i towerPos;
    sf::Vector2i getTargetPos(WaveManager& waveManager);
public:
    virtual ~Tower();
    Tower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player& player);
    void update(float deltaTime, ProjectileManager& projectileManager, WaveManager& waveManager);
    void setTowerPos(sf::Vector2i pos);
    int getRange() const;
    sf::Vector2i getTowerPos() const;
    virtual void attack(WaveManager& waveManager, ProjectileManager& projectileManager) = 0;
    void render(sf::RenderWindow& window);
};

#endif //TOWER_H
