//
// Created by Jesper Rudegran on 2024-12-31.
//

#ifndef TOWER_H
#define TOWER_H

#include "../enemy_code/Enemy.h"
#include "../GameObject.h"
#include "../Player.h"
#include "../projectile_code/ProjectileManager.h"

//class ProjectileManager;

class Tower : public GameObject {
    int range;
    float damage;
    float attackSpeed;
    float attackTimer = 0.0f;
    int cost;
    ProjectileManager* projectileManager = nullptr;
    Enemy* target = nullptr;
    sf::Vector2i towerPos;
    //ProjectileManager* projectileManager = nullptr;
public:
    Tower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player* player);
    virtual void attack();
    void setTarget(Enemy* enemy);
    void setTowerPos(sf::Vector2i pos);
    void update(float deltaTime);
    ProjectileManager* getProjectileManager() { return projectileManager; }
    void setProjectileManager(ProjectileManager* projectileManager) { this->projectileManager = projectileManager; }
    Enemy* getTarget() { return target; }

    virtual void render(sf::RenderWindow& window) = 0;
};



#endif //TOWER_H
