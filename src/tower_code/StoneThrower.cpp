//
// Created by Jesper Rudegran on 2024-12-31.
//

#include "StoneThrower.h"

#include <iostream>

StoneThrower::StoneThrower(int range, float damage, float attackSpeed, int cost, const std::string &textureFile, Player* player, ProjectileManager* projectileManager): Tower(range, damage, attackSpeed, cost, textureFile, player) {
    setProjectileManager(projectileManager);
}

void StoneThrower::attack() {
    //Tower::attack();
    std::cout << "StoneThrower attack" << std::endl;
    //cout << "Tower pos, " << getPosition().x << getPosition().y << endl;
    getProjectileManager()->addProjectile(sf::Vector2i(this->getPosition()), sf::Vector2i(200, 200), 10, 10, "../src/assets/projectiles/stone.png");
}

void StoneThrower::update() {
}

void StoneThrower::render(sf::RenderWindow &window) {
    Tower::render(window);
}
