//
// Created by Jesper Rudegran on 2024-12-31.
//

#ifndef TOWER_H
#define TOWER_H

#include "../enemy_code/Enemy.h"
#include "../GameObject.h"
#include "../Player.h"


class Tower : public GameObject {
    int range;
    float damage;
    float attackSpeed;
    int cost;
    Enemy* target = nullptr;
    sf::Vector2i towerPos;
    //ProjectileManager* projectileManager = nullptr;
public:
    Tower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player* player);
    virtual void attack();
    void setTarget(Enemy* enemy);
    void setTowerPos(sf::Vector2i pos);
    void update();


    virtual void render(sf::RenderWindow& window) = 0;
};



#endif //TOWER_H
