#ifndef STONETHROWER_H
#define STONETHROWER_H
#include "Tower.h"

class StoneThrower : public Tower {
  public:
    StoneThrower(int range, float damage, float attackSpeed, int cost, const std::string& textureFile, Player& player);
};

#endif //STONETHROWER_H
