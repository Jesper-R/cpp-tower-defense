#ifndef STONETHROWER_H
#define STONETHROWER_H
#include "Tower.h"

class StoneThrower : public Tower {
  public:
    ~StoneThrower();
    StoneThrower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player& player);
    void attack(WaveManager& waveManager, ProjectileManager& projectileManager) override;
};

#endif //STONETHROWER_H
