//
// Created by Jesper Rudegran on 2024-12-31.
//

#ifndef STONETHROWER_H
#define STONETHROWER_H
#include "Tower.h"


class StoneThrower : public Tower {
  public:
    StoneThrower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player* player, ProjectileManager* projectileManager);
    void attack() override;
    void update();
    void render(sf::RenderWindow& window) override;
};



#endif //STONETHROWER_H
