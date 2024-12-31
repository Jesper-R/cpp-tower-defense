//
// Created by Jesper Rudegran on 2024-12-31.
//

#include "StoneThrower.h"

StoneThrower::StoneThrower(int range, float damage, float attackSpeed, int cost, const std::string &textureFile, Player* player): Tower(range, damage, attackSpeed, cost, textureFile, player) {
}

void StoneThrower::attack() {
    Tower::attack();
}

void StoneThrower::render(sf::RenderWindow &window) {
    Tower::render(window);
}
