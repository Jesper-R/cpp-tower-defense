#include "StoneThrower.h"

#include <iostream>

StoneThrower::~StoneThrower() {
    cout << "StoneThrower destructor" << endl;
}

StoneThrower::StoneThrower(int range, float damage, float attackSpeed, int cost, const std::string &textureFile, Player& player): Tower(range, damage, attackSpeed, cost, textureFile, player) {}
