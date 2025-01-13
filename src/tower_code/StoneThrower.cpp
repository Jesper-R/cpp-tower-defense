#include "StoneThrower.h"
#include <iostream>

StoneThrower::StoneThrower(int range, float damage, float attackSpeed, int cost, const std::string &textureFile, Player* player, ProjectileManager* projectileManager, WaveManager* waveManager): Tower(range, damage, attackSpeed, cost, textureFile, player, waveManager) {
    //setProjectileManager(projectileManager);
}
